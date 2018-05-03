/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:36:55 by egoodale          #+#    #+#             */
/*   Updated: 2018/04/08 16:45:49 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_rotation(int keycode, t_fdf *fdf)
{
	if (keycode == K_ROTX_N)
		set_vector_rot(fdf, MOV_ROTX_N, 'X');
	else if (keycode == K_ROTX_P)
		set_vector_rot(fdf, MOV_ROTX_P, 'X');
	else if (keycode == K_ROTY_N)
		set_vector_rot(fdf, MOV_ROTY_N, 'Y');
	else if (keycode == K_ROTY_P)
		set_vector_rot(fdf, MOV_ROTY_P, 'Y');
	else if (keycode == K_ROTZ_N)
		set_vector_rot(fdf, MOV_ROTZ_N, 'Z');
	else if (keycode == K_ROTZ_P)
		set_vector_rot(fdf, MOV_ROTZ_P, 'Z');
}

static void	key_translation(int keycode, t_fdf *fdf)
{
	if (keycode == K_LEFT && check_corner(fdf, 1))
		set_vector_trans(fdf, MOV_LEFT, 0, 0);
	else if (keycode == K_RIGHT && check_corner(fdf, 2))
		set_vector_trans(fdf, MOV_RIGHT, 0, 0);
	else if (keycode == K_UP && check_corner(fdf, 3))
		set_vector_trans(fdf, 0, MOV_UP, 0);
	else if (keycode == K_DOWN && check_corner(fdf, 4))
		set_vector_trans(fdf, 0, MOV_DOWN, 0);
}

static void	key_scale(int keycode, t_fdf *fdf)
{
	if (keycode == K_ZOOM_IN)
		set_vector_scale(fdf, SCALE_IN, 'A');
	else if (keycode == K_ZOOM_OUT)
		set_vector_scale(fdf, SCALE_OUT, 'A');
	else if (keycode == K_SCALE_X_IN)
		set_vector_scale(fdf, SCALE_IN, 'X');
	else if (keycode == K_SCALE_X_OUT)
		set_vector_scale(fdf, SCALE_OUT, 'X');
	else if (keycode == K_SCALE_Y_IN)
		set_vector_scale(fdf, SCALE_IN, 'Y');
	else if (keycode == K_SCALE_Y_OUT)
		set_vector_scale(fdf, SCALE_OUT, 'Y');
}

static void	key_toggle_overlay(int keycode, t_fdf *fdf)
{
	if (keycode == K_X_OVER)
		fdf->overlay = 'X';
	else if (keycode == K_Y_OVER)
		fdf->overlay = 'Y';
	else if (keycode == K_A_OVER)
		fdf->overlay = 'A';
}

int			key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	key_rotation(keycode, fdf);
	key_translation(keycode, fdf);
	key_scale(keycode, fdf);
	key_toggle_overlay(keycode, fdf);
	redraw_image(fdf);
	return (0);
}
