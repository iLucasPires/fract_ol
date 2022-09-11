/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:59:12 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/11 15:04:14 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libraries.h"

void	re_render(t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	draw_fractal(&data->mlx, &data->var);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	menu(&data->mlx);
}

static void	pix_put_to_img(t_mlx *mlx, t_var *var, int *axle, int result)
{
	char	*pixel;
	int		aux_pixel[3];

	aux_pixel[0] = axle[I] * mlx->line_len;
	aux_pixel[1] = axle[R] * (mlx->bpp / 8);
	pixel = mlx->addr + aux_pixel[0] + aux_pixel[1];
	if (result == var->max_iteration)
		aux_pixel[2] = 0x000000;
	else
		aux_pixel[2] = set_color(result, var);
	*(unsigned int *)pixel = aux_pixel[2];
}

int	draw_fractal(t_mlx *mlx, t_var *var)
{
	int	axle[2];
	int	result;

	axle[R] = -1;
	while (++axle[R] < WIDTH)
	{
		axle[I] = -1;
		while (++axle[I] < HEIGHT)
		{
			var->center[R] = var->max[R] - var->min[R];
			var->center[I] = var->max[I] - var->min[I];
			var->complex[R] = var->min[R] + (var->center[R] * (axle[R]
						/ (double)WIDTH));
			var->complex[I] = var->min[I] + (var->center[I] * (axle[I]
						/ (double)HEIGHT));
			result = var->fractal(var->complex, var->max_iteration);
			pix_put_to_img(mlx, var, axle, result);
		}
	}
	return (0);
}
