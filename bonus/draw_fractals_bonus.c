/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:59:12 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/09 19:00:01 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	set_color(int i, int max)
{
	int		rbg[3];
	double	t;

	t = (double)i / (double)max;
	rbg[0] = (int)(9 * (1 - t) * t * t * t * 255);
	rbg[1] = (int)(15 * pow((1 - t), 2) * t * t * 255);
	rbg[2] = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (rbg[0] << 16 | rbg[1] << 8 | rbg[2]);
}

void	re_render(t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	draw_fractal(&data->mlx, &data->var);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
}

void	pix_put_to_img(t_mlx *mlx, t_var *var, int *axle, int result)
{
	char	*pixel;
	int		aux_pixel[3];

	aux_pixel[0] = axle[I] * mlx->line_len;
	aux_pixel[1] = axle[R] * (mlx->bpp / 8);
	pixel = mlx->addr + aux_pixel[0] + aux_pixel[1];
	if (result == var->max_interation)
		aux_pixel[2] = 0x000000;
	else
		aux_pixel[2] = set_color(result, 100);
	*(unsigned int *)pixel = aux_pixel[2];
}

int	draw_fractal(t_mlx *mlx, t_var *var)
{
	int	axle[2];
	int	result;

	axle[R] = 0;
	while (++axle[0] < WIDTH)
	{
		axle[I] = 0;
		while (++axle[1] < HEIGHT)
		{
			var->center[R] = var->max[R] - var->min[R];
			var->center[I] = var->max[I] - var->min[I];
			var->complex[R] = var->min[R] + axle[R] * var->center[R] / WIDTH;
			var->complex[I] = var->min[I] + axle[I] * var->center[I] / HEIGHT;
			result = var->fractal(var->complex, var->max_interation);
			pix_put_to_img(mlx, var, axle, result);
		}
	}
	return (0);
}
