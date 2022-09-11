/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_warnings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:53:59 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/10 21:50:18 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libraries.h"

void	erro_ptr(void *ptr, const char *msg)
{
	if (!ptr)
	{
		ft_printf("\033[0;31mError: Failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	else
		ft_printf("\033[0;32mSuccess: %s OK\n", msg);
}

void	error_argument(int err)
{
	if (err == MISSING_ARG)
	{
		ft_printf("\033[0;31mError: Missing argument or invite number\n");
		ft_printf("\033[0;35mif you are using Julia fractal, you must\n");
		ft_printf("add the complex number as a second argument\n");
		ft_printf("\033[0;37mExample: ./fractol Julia -0.4 0.6\n");
	}
	else if (err == INVALID_FRACTAL)
	{
		ft_printf("\033[0;31mError: Invalid fractal name\n");
		ft_printf("\033[0;37mUsage: ./fractol [fractal name]\n");
		ft_printf("\033[0;35mAvailable fractals\n");
		ft_printf("[1] mandelbrot\n[2] julia\n");
	}
	exit(EXIT_FAILURE);
}

void	menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 10, 20, 0x00FFFFFF, "Fractol");
	mlx_string_put(mlx->mlx, mlx->win, 10, 40, 0x00FFFFFF, "Zoom: Scroll");
	mlx_string_put(mlx->mlx, mlx->win, 10, 60, 0x00FFFFFF, "Reset: R");
	mlx_string_put(mlx->mlx, mlx->win, 10, 80, 0x00FFFFFF, "Exit: ESC");
}