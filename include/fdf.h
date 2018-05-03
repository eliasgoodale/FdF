/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:22:46 by egoodale          #+#    #+#             */
/*   Updated: 2018/04/09 13:13:33 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FDF_H
#	define FDF_H

#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../minilibx/mlx.h"

#define W_HEIGHT 2000
#define W_WIDTH	3400

#define K_SCALE_X_IN 0
#define K_SCALE_X_OUT 2
#define K_SCALE_Y_IN 13
#define K_SCALE_Y_OUT 1

#define K_X_OVER 91
#define K_Y_OVER 89
#define K_A_OVER 92

#define K_ESC 53
#define K_ROTX_N 86
#define K_ROTX_P 83
#define K_ROTY_N 87
#define K_ROTY_P 84
#define K_ROTZ_N 88
#define K_ROTZ_P 85

#define K_LEFT 123
#define K_RIGHT 124
#define K_DOWN 125
#define K_UP 126

#define K_ZOOM_IN 69
#define K_ZOOM_OUT 78

#define MOV_ROTX_N -M_PI / 64
#define MOV_ROTX_P M_PI / 64
#define MOV_ROTY_N -M_PI / 64
#define MOV_ROTY_P M_PI / 64
#define MOV_ROTZ_N -M_PI / 64
#define MOV_ROTZ_P M_PI / 64

#define MOV_LEFT -100
#define MOV_RIGHT 100
#define MOV_UP -100
#define MOV_DOWN 100

#define SCALE_IN 1.1
#define SCALE_OUT 0.9

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	double		s;
	int			color;
}				t_point;

typedef struct	s_fdf
{
	int			fd;
	t_point		**map;
	t_point		center;
	char		*filename;
	int			x_max;
	int			y_max;
	void		*mlx;
	void		*win;
	void		*img;
	char		*p_img;
	int			bpp;
	int			s_line;
	int			ed;
	char		overlay;
	int			state;
}				t_fdf;

typedef struct	s_matrix
{
	double		a1;
	double		a2;
	double		a3;
	double		a4;
	double		b1;
	double		b2;
	double		b3;
	double		b4;
	double		c1;
	double		c2;
	double		c3;
	double		c4;
	double		d1;
	double		d2;
	double		d3;
	double		d4;
}				t_matrix;

void			parse_input(t_fdf *fdf);
int				init_fdf(t_fdf *fdf);
int				point_row_get(char *line, int line_nb,
				t_point *point_row, t_fdf *fdf);
void			init_window(int w, int h, t_fdf *fdf);
void			draw_map(t_fdf *fdf);
t_matrix		*translate(double x, double y, double z);
t_matrix		*f_scale(double s, char axis);
t_matrix		*rotate_x(double angle);
t_matrix		*rotate_y(double angle);
t_matrix		*rotate_z(double angle);
int				key_hook(int keycode, t_fdf *fdf);
void			calibr_point(t_point *p, t_matrix *m, t_fdf *fdf);
void			calibr_points(t_matrix *m, t_fdf *fdf);
void			set_vector_rot(t_fdf *fdf, double rot, char axis);
void			set_vector_trans(t_fdf *fdf, double x, double y, double z);
void			set_vector_scale(t_fdf *fdf, double s, char axis);
int				get_color(t_point *point1, t_point *point2);
void			get_center(t_fdf *fdf);
void			redraw_image(t_fdf *fdf);
void			set_normal(t_fdf *fdf);
int				do_render(t_point *point1);
int				expose_hook(t_fdf *fdf);
void			throw_err(int code);
void			get_file(t_fdf *fdf);
int				check_corner(t_fdf *fdf, int corner);

#	endif
