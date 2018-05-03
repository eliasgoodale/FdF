/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:13:00 by egoodale          #+#    #+#             */
/*   Updated: 2018/04/09 13:13:18 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(t_point *point1, t_point *point2)
{
	int		color;
	int		z;

	if (point2->color > point1->color)
		z = point2->color;
	else
		z = point1->color;
	if (z < 0)
		color = 0x0D6386 + (z * 100);
	else if (z >= 0 && z < 10)
		color = 0xFF0000 + (z * 10000);
	else if (z >= 10 && z < 20)
		color = 0x00FF00 + (z * 10000);
	else if (z >= 20 && z < 50)
		color = 0x0000FF + (z * 10000);
	else if (z >= 50 && z < 70)
		color = 0xFFFFFF - (z * 10000);
	else if (z >= 70)
		color = (z * 10000);
	else
		color = 0;
	return (color);
}

void	get_center(t_fdf *fdf)
{
	t_point p;
	int		yl;
	int		xl;

	p = fdf->center;
	yl = fdf->y_max;
	xl = fdf->x_max;
	p.x = (fdf->map[fdf->y_max - 1][fdf->x_max - 1].x +
			fdf->map[0][0].x) / 2;
	p.y = (fdf->map[fdf->y_max - 1][fdf->x_max - 1].y +
			fdf->map[0][0].y) / 2;
	fdf->center = p;
}

void	redraw_image(t_fdf *fdf)
{
	fdf->img = mlx_new_image(fdf->mlx, W_WIDTH + 100, W_HEIGHT + 100);
	fdf->p_img = mlx_get_data_addr(fdf->img, &(fdf->bpp),
	&(fdf->s_line), &(fdf->ed));
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, -50, -50);
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_loop(fdf->mlx);
}

void	set_normal(t_fdf *fdf)
{
	int		w;
	int		h;
	double	s;

	w = (W_WIDTH + 100) / 2;
	h = (W_HEIGHT + 100) / 2;
	fdf->center.x == 0 ? fdf->center.x = 10 : fdf->center.x;
	s = (w - 1200) / (fdf->center.x);
	set_vector_trans(fdf, -fdf->center.x + w, -fdf->center.y + h, 0);
	set_vector_scale(fdf, s, 'A');
}

int		do_render(t_point *point1)
{
	if (!(point1->x > W_WIDTH + 100 || point1->x <= 0 ||
		point1->y > W_HEIGHT + 100 || point1->y <= 0))
		return (1);
	else
		return (0);
}
