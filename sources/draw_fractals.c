/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:59:12 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/09 18:32:55 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libraries.h"

static int	set_color(int i, int max)
{
	int		rbg[3];
	double	t;

	t = (double)i / (double)max;
	rbg[0] = sin(0.08 * i + 10 + 10) * 125 + 126;
	rbg[1] = sin(0.08 * i + 1 + 52) * 125 + 126;
	rbg[2] = sin(0.08 * i + 10 + 0) * 125 + 126;
	return (rbg[0] << 16 | rbg[1] << 8 | rbg[2]);
}

void	re_render(t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	draw_fractal(&data->mlx, &data->var);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
}

static void	pix_put_to_img(t_mlx *mlx, t_var *var, int *axle, int result)
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

	axle[R] = -1;
	while (++axle[R] < WIDTH)
	{
		axle[I] = -1;
		while (++axle[I] < HEIGHT)
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
