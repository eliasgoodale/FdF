/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:22:46 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/26 18:29:40 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FDF_H
#	define FDF_H

#include <stdio.h> //REMOVE LATER
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#define W_S(x) (x == ' ' || x == '\n' ? 1 : 0)
#define W_HEIGHT 1920
#define W_WIDTH	1080
#include "minilibx/mlx.h"

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	double		s;
	int			z_color;
}				t_point;

typedef struct 	s_line
{
	t_point		**points;
	int			len;
}				t_line;

typedef struct	s_map
{
	t_line		**lines;
	int			len;
}				t_map;

typedef struct	s_fdf
{
	int			fd;
	t_map		*map;
	t_point		center;
	char		*filename;
	size_t		line_len;
	size_t		lines;
	void		*mlx;
	void		*win;
	double	pts[4];
	double	err;
	double	dx;
	double	dy;
	double	sx;
	double	sy;
	double	d;
	double	incry;
	double	incrne;
	double	slopegt1;

}				t_fdf;
void	parse_input(t_fdf *fdf);
void	draw_lines(t_fdf *fdf);
#	endif
