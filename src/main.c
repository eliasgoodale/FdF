/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:03:09 by egoodale          #+#    #+#             */
/*   Updated: 2018/04/09 13:14:09 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_fdf *fdf;

	if (ac == 2)
	{
		if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
			throw_err(2);
		fdf->filename = av[1];
		get_file(fdf);
		parse_input(fdf);
		if (fdf->y_max == 0 || fdf->x_max == 0)
			throw_err(1);
		get_center(fdf);
		init_window(W_WIDTH, W_HEIGHT, fdf);
		set_normal(fdf);
		mlx_expose_hook(fdf->win, expose_hook, fdf);
		mlx_hook(fdf->win, 2, 3, key_hook, fdf);
		mlx_loop(fdf->mlx);
	}
	else
		throw_err(4);
	return (0);
}
