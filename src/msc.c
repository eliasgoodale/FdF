/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:12:49 by egoodale          #+#    #+#             */
/*   Updated: 2018/04/08 16:51:54 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	throw_err(int code)
{
	if (code == 1)
		ft_putstr("Map Error\n");
	else if (code == 2)
		ft_putstr("Malloc Error\n");
	else if (code == 3)
		ft_putstr("File Error\n");
	else if (code == 4)
		ft_putstr("Usage: ./fdf <map.fdf>\n");
	exit(0);
}

void	get_file(t_fdf *fdf)
{
	if ((fdf->fd = open(fdf->filename, O_RDONLY)) < 0)
		throw_err(3);
	return ;
}

int		expose_hook(t_fdf *fdf)
{
	redraw_image(fdf);
	return (0);
}

int		check_corner(t_fdf *fdf, int corner)
{
	if (corner == 1)
		if (fdf->map[0][0].x >= -5000)
			return (1);
	if (corner == 2)
		if (fdf->map[fdf->y_max - 1][fdf->x_max - 1].x <= W_WIDTH + 5000)
			return (1);
	if (corner == 3)
		if (fdf->map[0][fdf->x_max - 1].y >= -5000)
			return (1);
	if (corner == 4)
		if (fdf->map[fdf->y_max - 1][0].y <= W_HEIGHT - 30)
			return (1);
	return (0);
}
