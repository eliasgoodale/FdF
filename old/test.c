/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:35:11 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/21 19:03:17 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include <math.h>
#define MAX 20
#define ABS_V(x) (x < 0 ? -x : x)

void ft_swap(int* a,int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
 
void midpointline(int x1,int y1,int x2,int y2, void *mlx, void *win)
{
	int		dx = 0;
	int		dy = 0;
	int		d = 0;
	int		incry = 0;
	int		incre = 0;
	int		incrne = 0;
	int		slopegt1 = 0;
	
	dx=ABS_V(x1-x2);
	dy=ABS_V(y1-y2);
	if(dy>dx)
	{
		ft_swap(&x1,&y1);
		ft_swap(&x2,&y2);
		ft_swap(&dx,&dy);
		slopegt1=1;
	}
	if(x1>x2)
	{
		ft_swap(&x1,&x2);
		ft_swap(&y1,&y2);
	}
	if(y1>y2)
		incry=-1;
	else
		incry=1;
	d=2*dy-dx;
	incre=2*dy;
	incrne=2*(dy-dx);
	while(x1<x2)
	{
		if(d<=0)
			d+=incre;
		else
		{
			d+=incrne;
			y1+=incry;
		}
		x1++;
		if(slopegt1)
			mlx_pixel_put(mlx, win,y1, x1, 0xFFFFFF);
		else
			mlx_pixel_put(mlx, win, x1, y1, 0xFFFFFF);
	}
}
 

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}

int main()
{	
	void    *mlx = mlx_init();
 	void    *win = mlx_new_window(mlx, 500, 500, "mlx_42");
	int pt1[2] = {200, 200};
	int pt2[2] = {300, 300};
	int pt3[2] = {300, 200};
	int pt4[2] = {200, 300};;

	/*mlx_pixel_put(mlx, win,10, 10, 0xFFFFFF);
	mlx_pixel_put(mlx, win,490, 490, 0xFFFFFF);
	mlx_pixel_put(mlx, win,10, 490, 0xFFFFFF);
	mlx_pixel_put(mlx, win,490, 10, 0xFFFFFF);*/
	midpointline(pt1[0], pt1[1], pt3[0], pt3[1], mlx, win);
	midpointline(pt1[0], pt1[1], pt4[0], pt4[1], mlx, win);
	midpointline(pt2[0], pt2[1], pt3[0], pt3[1], mlx, win);
	midpointline(pt2[0], pt2[1], pt4[0], pt4[1], mlx, win);
	midpointline(pt3[0], pt3[1], pt1[0], pt1[1], mlx, win);
	midpointline(pt3[0], pt3[1], pt4[0], pt4[1], mlx, win);
	midpointline(pt4[0], pt4[0], pt1[0], pt1[0], mlx, win);

	//midpointline(pt1[0], pt1[1], pt4[0], pt4[1], mlx, win);

	mlx_loop(mlx);
}
