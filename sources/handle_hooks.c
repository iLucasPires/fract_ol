/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:58:48 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/10 05:51:04 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libraries.h"

static int	handle_mouse(int key, int x, int y, t_data *data)
{
	data->var.axle[R] = x;
	data->var.axle[I] = y;
	if (key == 4 || key == 5)
	{
		zoom_fractal(key, &data->var);
		re_render(data);
	}
	return (0);
}

static int	handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	mlx_destroy_display(data->mlx.mlx);
	free(data->mlx.mlx);
	exit(0);
}

static int	handle_key(int key, t_data *data)
{
	if (key == ESC)
		handle_close(data);
	return (0);
}

int	handle_hooks(t_data *data)
{
	mlx_hook(data->mlx.win, 17, 0, handle_close, data);
	mlx_mouse_hook(data->mlx.win, handle_mouse, data);
	mlx_key_hook(data->mlx.win, handle_key, data);
	mlx_expose_hook(data->mlx.win, re_render, data);
	return (0);
}
