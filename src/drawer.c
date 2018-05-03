/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:16:17 by egoodale          #+#    #+#             */
/*   Updated: 2018/04/09 13:15:40 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_window(int weight, int height, t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, weight, height, fdf->filename);
}

static void	line_setup(t_point *p1, t_point *p2, double *tab)
{
	tab[0] = fabs(p1->x - p2->x);
	tab[1] = p1->x < p2->x ? 1 : -1;
	tab[2] = fabs(p1->y - p2->y);
	tab[3] = p1->y < p2->y ? 1 : -1;
	tab[4] = (tab[0] > tab[2] ? tab[0] : -tab[2]) * 0.5;
}

static void	draw_point(t_point *point, t_fdf *fdf, int color)
{
	int		i;

	i = ((int)point->x * 4) + ((int)point->y * fdf->s_line);
	fdf->p_img[i] = color;
	fdf->p_img[++i] = color >> 8;
	fdf->p_img[++i] = color >> 16;
}

static void	draw_line(t_point p1, t_point p2, t_fdf *fdf)
{
	double		tab[6];

	if (!do_render(&p1) && !do_render(&p2))
		return ;
	line_setup(&p1, &p2, tab);
	fdf->state = 1;
	while (fdf->state == 1 &&
	!((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y))
	{
		do_render(&p1) ? draw_point(&p1, fdf, get_color(&p1, &p2)) : 0;
		tab[5] = tab[4];
		fdf->state = 0;
		if (tab[5] > -tab[0] && (int)p1.x != (int)p2.x)
		{
			tab[4] -= tab[2];
			p1.x += tab[1];
			fdf->state = 1;
		}
		if (tab[5] < tab[2] && (int)p1.y != (int)p2.y)
		{
			tab[4] += tab[0];
			p1.y += tab[3];
			fdf->state = 1;
		}
	}
}

void		draw_map(t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	p1;

	y = 0;
	while (y < fdf->y_max)
	{
		x = 0;
		while (x < (fdf->x_max))
		{
			p1 = fdf->map[y][x];
			if (x < fdf->x_max - 1 &&
			(fdf->overlay == 'A' || fdf->overlay == 'X'))
				draw_line(p1, fdf->map[y][x + 1], fdf);
			if (y < fdf->y_max - 1 &&
			(fdf->overlay == 'A' || fdf->overlay == 'Y'))
				draw_line(p1, fdf->map[y + 1][x], fdf);
			x++;
		}
		y++;
	}
}
