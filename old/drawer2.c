/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 13:50:08 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/26 21:02:44 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>

void ft_swap(double* a, double* b)
{
    double t=*a;
    *a=*b;
    *b=t;
}
 
void midpointline(double x1, double  y1, double x2, double y2, void *mlx, void *win, double z)
{
    double	dx = 0;
    double	dy = 0;
    double	d = 0;
    double	incry = 0;
    double	incre = 0;
    double	incrne = 0;
    double slopegt1 = 0;
    
    dx = fabs(x1-x2);
    dy = fabs(y1-y2);
    if(dy>dx)
    {   
        ft_swap(&x1,&y1);
        ft_swap(&x2,&y2);
        ft_swap(&dx,&dy);
        slopegt1 = 1;
    }   
    if(x1>x2)
    {   
        ft_swap(&x1,&x2);
        ft_swap(&y1,&y2);
    }   
    if(y1>y2)
        incry =- 1;
    else
        incry = 1;
    d = 2*dy-dx;
    incre = 2*dy;
    incrne= 2 * (dy-dx);
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
            mlx_pixel_put(mlx, win, (int)y1, (int)x1, 0xFFFFFF - (z * 150));
        else
            mlx_pixel_put(mlx, win, (int)x1, (int)y1, 0xFFFFFF -  (z * 150));
    }   
}

void	draw_edge(t_fdf *fdf, int i, int j)
{
	int k = j;

	while(--j >= 0)
			midpointline(fdf->map->lines[i]->points[j + 1]->x, fdf->map->lines[i]->points[j + 1]->y, fdf->map->lines[i]->points[j]->x, fdf->map->lines[i]->points[j]->y, fdf->mlx, fdf->win, fdf->map->lines[i]->points[j]->z);
	while(--i >= 0 )
		midpointline(fdf->map->lines[i + 1]->points[k]->x, fdf->map->lines[i + 1]->points[k]->y, fdf->map->lines[i]->points[k]->x, fdf->map->lines[i]->points[k]->y, fdf->mlx, fdf->win, fdf->map->lines[i]->points[k]->z);
}
void	init_fdf_draw(t_fdf *fdf, int i, int j)
{
	fdf->pts[0] = fdf->map->lines[i]->points[j]->x;
	fdf->pts[1] = fdf->map->lines[i]->points[j]->y;
	fdf->pts[2] = fdf->map->lines[i]->points[j + 1]->x;
	fdf->pts[3] = fdf->map->lines[i + 1]->points[j]->y;
}


void	draw_lines(t_fdf *fdf)
{
	int points[3];
	int i;
	int j;

	i = 0;
	j = 0;
	while(++i < fdf->map->len - 1)
	{
		j = 0;
		while(++j < fdf->map->lines[i]->len - 1)
		{
		   fdf->map->lines[i]->points[j + 1]->x = fdf->map->lines[i]->points[j + 1]->x + fdf->map->lines[i]->points[j + 1]->z;
		   fdf->map->lines[i + 1]->points[j]->y = fdf->map->lines[i + 1]->points[j]->y + fdf->map->lines[i + 1]->points[j]->z; 
		}
	}
	i = -1;
	j = -1;
	while(++i < fdf->map->len - 1)
	{
		j = -1;
		while(++j < fdf->map->lines[i]->len - 1)
		{
			midpointline(fdf->map->lines[i]->points[j]->x , fdf->map->lines[i]->points[j]->y, fdf->map->lines[i]->points[j + 1]->x, fdf->map->lines[i]->points[j + 1]->y, fdf->mlx, fdf->win, fdf->map->lines[i]->points[j + 1]->z);
			midpointline(fdf->map->lines[i]->points[j]->x, fdf->map->lines[i]->points[j]->y , fdf->map->lines[i + 1]->points[j]->x, fdf->map->lines[i + 1]->points[j]->y, fdf->mlx, fdf->win, fdf->map->lines[i + 1]->points[j]->z);
		}
	}
	draw_edge(fdf, i, j);
 	mlx_loop(fdf->mlx);
}	

			
