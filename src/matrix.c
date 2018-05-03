/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:04:55 by egoodale          #+#    #+#             */
/*   Updated: 2018/04/08 16:50:32 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*rotate_x(double uc_dist)
{
	t_matrix *m;

	if (!(m = (t_matrix*)ft_memalloc(sizeof(t_matrix))))
		throw_err(2);
	m->a1 = 1;
	m->b2 = cos(uc_dist);
	m->b3 = -sin(uc_dist);
	m->c2 = sin(uc_dist);
	m->c3 = cos(uc_dist);
	m->d4 = 1;
	return (m);
}

t_matrix	*rotate_y(double uc_dist)
{
	t_matrix *m;

	if (!(m = (t_matrix*)ft_memalloc(sizeof(t_matrix))))
		throw_err(2);
	m->a1 = cos(uc_dist);
	m->a3 = sin(uc_dist);
	m->c1 = -sin(uc_dist);
	m->c3 = cos(uc_dist);
	m->b2 = 1;
	m->d4 = 1;
	return (m);
}

t_matrix	*rotate_z(double uc_dist)
{
	t_matrix *m;

	if (!(m = (t_matrix*)ft_memalloc(sizeof(t_matrix))))
		throw_err(2);
	m->a1 = cos(uc_dist);
	m->a2 = -sin(uc_dist);
	m->b1 = sin(uc_dist);
	m->b2 = cos(uc_dist);
	m->c3 = 1;
	m->d4 = 1;
	return (m);
}

t_matrix	*translate(double x, double y, double z)
{
	t_matrix *m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		throw_err(2);
	m->a4 = x;
	m->b4 = y;
	m->c4 = z;
	m->a1 = 1;
	m->b2 = 1;
	m->c3 = 1;
	m->d4 = 1;
	return (m);
}

t_matrix	*f_scale(double s, char axis)
{
	t_matrix *m;

	if (!(m = (t_matrix *)ft_memalloc(sizeof(t_matrix))))
		throw_err(2);
	m->a1 = 1;
	m->b2 = 1;
	m->c3 = 1;
	m->d4 = 1;
	if (axis == 'A')
	{
		m->a1 = s;
		m->b2 = s;
		m->c3 = s;
	}
	else if (axis == 'X')
		m->a1 = s;
	else if (axis == 'Y')
		m->b2 = s;
	return (m);
}
