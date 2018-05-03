/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:19:20 by egoodale          #+#    #+#             */
/*   Updated: 2018/04/08 18:02:24 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		init_fdf(t_fdf *fdf)
{
	char	*line;

	fdf->x_max = 0;
	fdf->y_max = 0;
	fdf->overlay = 'A';
	while (get_next_line(fdf->fd, &line) > 0)
	{
		fdf->y_max++;
		free(line);
	}
	if (!(fdf->map = (t_point **)malloc(sizeof(t_point *) * fdf->y_max)))
		return (-1);
	close(fdf->fd);
	fdf->fd = open(fdf->filename, O_RDONLY);
	return (1);
}

int		point_row_get(char *line, int line_nb, t_point *point_row, t_fdf *fdf)
{
	char	**array_str;
	int		i;
	t_point	a_point;

	i = 0;
	array_str = ft_strsplit(line, ' ');
	while (array_str[i])
		i++;
	if (fdf->x_max && fdf->x_max != i)
		throw_err(1);
	point_row = (t_point *)malloc(sizeof(t_point) * i);
	i = -1;
	while (array_str[++i])
	{
		a_point.x = i * 20;
		a_point.y = line_nb * 20;
		a_point.z = ft_atoi(array_str[i]);
		a_point.s = 1;
		a_point.color = a_point.z;
		point_row[i] = a_point;
		free(array_str[i]);
	}
	fdf->map[line_nb] = point_row;
	return (i);
}

void	parse_input(t_fdf *fdf)
{
	char	*line;
	int		l_n;
	t_point	*point_row;

	l_n = 0;
	point_row = NULL;
	if (init_fdf(fdf) < 0)
		throw_err(0);
	while (get_next_line(fdf->fd, &line) > 0)
	{
		fdf->x_max = point_row_get(line, l_n, point_row, fdf);
		l_n++;
		free(point_row);
	}
}
