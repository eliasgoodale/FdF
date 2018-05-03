/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:04:07 by egoodale          #+#    #+#             */
/*   Updated: 2018/04/08 13:43:52 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calibr_point(t_point *p, t_matrix *m, t_fdf *fdf)
{
	double		cal_x;
	double		cal_y;
	double		cal_z;

	p->x -= fdf->center.x;
	p->y -= fdf->center.y;
	cal_x = p->x * m->a1 + p->y * m->a2 + p->z * m->a3 + p->s * m->a4;
	cal_y = p->x * m->b1 + p->y * m->b2 + p->z * m->b3 + p->s * m->b4;
	cal_z = p->x * m->c1 + p->y * m->c2 + p->z * m->c3 + p->s * m->c4;
	p->x = cal_x;
	p->y = cal_y;
	p->z = cal_z;
	p->x += fdf->center.x;
	p->y += fdf->center.y;
}

void	calibr_points(t_matrix *m, t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	while (++y < fdf->y_max)
	{
		x = -1;
		while (++x < fdf->x_max)
			calibr_point(&fdf->map[y][x], m, fdf);
	}
}

void	set_vector_rot(t_fdf *fdf, double rot, char axis)
{
	t_matrix *m_rot;

	if (axis == 'X')
		m_rot = rotate_x(rot);
	else if (axis == 'Y')
		m_rot = rotate_y(rot);
	else
		m_rot = rotate_z(rot);
	calibr_points(m_rot, fdf);
	free(m_rot);
}

void	set_vector_trans(t_fdf *fdf, double x, double y, double z)
{
	t_matrix *m_tran;

	m_tran = translate(x, y, z);
	calibr_points(m_tran, fdf);
	get_center(fdf);
	free(m_tran);
}

void	set_vector_scale(t_fdf *fdf, double s, char axis)
{
	t_matrix *m_tran;

	m_tran = f_scale(s, axis);
	calibr_points(m_tran, fdf);
	free(m_tran);
}
