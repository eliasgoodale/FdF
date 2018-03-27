/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:20:03 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/24 17:45:07 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int main (int ac, char **av)
{
	t_fdf	fdf;
	if (ac == 2)
	{
		fdf.filename = av[1];
		fdf.fd = open(fdf.filename, O_RDONLY);
		parse_input(&fdf);			
	}
	else
		write(1, "USAGE\n", 6);
	sleep(10000);
	return (0);
}



