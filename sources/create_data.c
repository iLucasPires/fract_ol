/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:56:33 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/11 13:33:50 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libraries.h"

void	init_var(t_var *var)
{
	var->max_iteration = 100;
	var->min[R] = -2.0;
	var->min[I] = -1.5;
	var->max[R] = 2.0;
	var->max[I] = var->min[I] + (var->max[R] - var->min[R]) * HEIGHT / WIDTH;
	var->complex[R] = 0;
	var->complex[I] = 0;
	var->axle[R] = 0;
	var->axle[I] = 0;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	erro_ptr(mlx->mlx, "mlx_init");
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fractol");
	erro_ptr(mlx->win, "mlx_new_window");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	erro_ptr(mlx->img, "mlx_new_image");
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_len,
			&mlx->endian);
}
