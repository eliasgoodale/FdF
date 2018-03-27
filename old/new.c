


#include "mlx.h"
#include "unistd.h"
#include <math.h>
#include "libft/ft_bzero.c"
#define MAX 20
#define ABS_V(x) (x < 0 ? -x : x)

typedef struct s_fdf
{
	void *mlx;
	void *win;
	int dy;
	int dx;
	int z;
	int pi;
	int sx;
	int sy;
	int pt1[2];
	int pt2[2];
	unsigned color;
}				t_fdf;



void draw_line(int x0, int y0, int x1, int y1, t_fdf *fdf)
{
    int dx, dy, p, x, y;
 
    dx=x1-x0;
    dy=y1-y0;
 
    x=x0;
    y=y0;
 
    p=2*dy-dx;
 
    while(x<x1)
    {
        if(p>=0)
        {
            mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF);
            y++;
            p=p+2*dy-2*dx;
        }
        else
        {
            mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF);
            p=p+2*dy;
        }
        x=x+1;
    }
}



/*void draw_line(int x0, int x1, int y0, int y1, t_fdf *fdf)
{
	int dy = ABS_V(y1 - y0);
	int dx = ABS_V(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int sy = y0 < y1 ? 1 : -1;
	int err = (dx > dy ? dx : -dy)/2;
	int e2;

	for(;;)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x0, y0, 0xFFFFFF);
		if (x0 == x1 && y0 == y1) 
			break;
		e2 = err;
		if (e2 > -dx) 
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += fdf->sy;
		}
	}
}	
{
	fdf->dy = ABS_V(y2 - y1);
	fdf->dx = ABS_V(x2 - x1);
	fdf->z = (2 * fdf->dy) - (2 * fdf->dx);
	fdf->pi = (2 * fdf->dy) - fdf->dx;
	
	while(x1 < x2)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x1, y1, 0xFFFFFF);
		if((fdf->pi = fdf->pi + fdf->z) > 0)
			y1++;
		x1++;
	}
	return (1);
}*/

void init_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 500, 500, "mlx_42");
	fdf->sx = 0;
	fdf->sy = 0;
	fdf->dy = 0;
	fdf->dx = 0;
	fdf->z = 0;
	fdf->pi = 0;
	ft_bzero(fdf->pt1, 2);
	ft_bzero(fdf->pt2, 2);
	fdf->color = 0xFFFFFF;
}

void plot_ellipse_rect(int x0, int y0, int x1, int y1, t_fdf *fdf)
{
	int a = ABS_V(x1 - x0);
	int b = ABS_V(y1 - y0); 
	int b1 = b & 1;
   	long dx = 4 * (1 - a) * b * b; 
	long dy = 4 * (b1 + 1) * a * a; /* error increment */
	long err = dx + dy + b1 * a * a, e2; /* error of 1.step */

   if (x0 > x1) { x0 = x1; x1 += a; } /* if called with swapped points */
   if (y0 > y1) y0 = y1; /* .. exchange them */
   y0 += (b + 1) / 2;
   y1 = y0-b1;   /* starting pixel */
   a *= 8 * a; b1 = 8 * b * b;
   do
   {
       mlx_pixel_put(fdf->mlx, fdf->win, x1, y0, fdf->color);/*   I. Quadrant */
       mlx_pixel_put(fdf->mlx, fdf->win, x0, y0, fdf->color);/*  II. Quadrant */
       mlx_pixel_put(fdf->mlx, fdf->win, x0, y1, fdf->color);/* III. Quadrant */
       mlx_pixel_put(fdf->mlx, fdf->win, x1, y1, fdf->color); /*  IV. Quadrant */
       e2 = 2 * err;
       if (e2 >= dx)
       {
          x0++;
          x1--;
          err += dx += b1;
       } /* x step */
       if (e2 <= dy)
       {
          y0++;
          y1--;
          err += dy += a;
       }  /* y step */ 
   } while (x0 <= x1);
   while (y0-y1 < b)
   {  /* too early stop of flat ellipses a=1 */
       mlx_pixel_put(fdf->mlx, fdf->win, x0 - 1, y0, fdf->color); /* -> finish tip of ellipse */
       mlx_pixel_put(fdf->mlx, fdf->win, x1 + 1, y0++, fdf->color); 
       mlx_pixel_put(fdf->mlx, fdf->win, x0 - 1, y1, fdf->color);
       mlx_pixel_put(fdf->mlx, fdf->win, x1 + 1, y1--, fdf->color);
   }
}
int main()
{
	t_fdf fdf;

	init_fdf(&fdf);

	int x0 = 100;
	int y0 = 100;
	int x1 = 101;
	int	y1 = 200;

	fdf.pt1[0] = x0;
	fdf.pt1[1] = y0;
	fdf.pt2[0] = x1;
	fdf.pt2[1] = y1;
	//plot_ellipse_rect(x0, y0, x1, y1, &fdf);
	draw_line(x0, y0, x1, y1, &fdf);
	mlx_loop(fdf.mlx);
}
