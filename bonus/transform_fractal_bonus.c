/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_fractal_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:58:52 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/11 19:13:32 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libraries_bonus.h"

int	move_fractal(int key, t_var *var)
{
	if (key == UP)
	{
		var->min[I] -= var->center[I] / 10;
		var->max[I] -= var->center[I] / 10;
	}
	else if (key == DOWN)
	{
		var->min[I] += var->center[I] / 10;
		var->max[I] += var->center[I] / 10;
	}
	else if (key == LEFT)
	{
		var->min[R] -= var->center[R] / 10;
		var->max[R] -= var->center[R] / 10;
	}
	else if (key == RIGHT)
	{
		var->min[R] += var->center[R] / 10;
		var->max[R] += var->center[R] / 10;
	}
	return (0);
}

void	zoom_fractal(int key, int x, int y, t_var *var)
{
	if (key == 4)
	{
		var->min[R] += var->center[R] * (x / (double)WIDTH) / 10;
		var->max[R] -= var->center[R] * (1 - x / (double)WIDTH) / 10;
		var->min[I] += var->center[I] * (y / (double)HEIGHT) / 10;
		var->max[I] -= var->center[I] * (1 - y / (double)HEIGHT) / 10;
		var->max_iteration += 10;
	}
	else if (key == 5)
	{
		var->min[R] -= var->center[R] * (x / (double)WIDTH) / 10;
		var->max[R] += var->center[R] * (1 - x / (double)WIDTH) / 10;
		var->min[I] -= var->center[I] * (y / (double)HEIGHT) / 10;
		var->max[I] += var->center[I] * (1 - y / (double)HEIGHT) / 10;
		if (var->max_iteration > 100)
			var->max_iteration -= 10;
	}
	ft_printf("%i\n", var->max_iteration);
}

int	set_color(int i, t_var *var)
{
	int	rbg[3];

	if (var->color == 1)
	{
		rbg[0] = sin(0.1 * i + 0) * 127 + 128;
		rbg[1] = sin(0.1 * i + 2) * 127 + 128;
		rbg[2] = sin(0.1 * i + 4) * 127 + 128;
	}
	else if (var->color == 2)
	{
		rbg[0] = sin(0.1 * i + 5) * 127 + 128;
		rbg[1] = sin(0.1 * i + 6) * 127 + 128;
		rbg[2] = sin(0.1 * i + 7) * 127 + 128;
	}
	else if (var->color == 3)
	{
		rbg[0] = sin(0.1 * i + 8) * 127 + 128;
		rbg[1] = sin(0.1 * i + 9) * 127 + 128;
		rbg[2] = sin(0.1 * i + 0) * 127 + 128;
	}
	if (var->color == 4)
		var->color = 1;
	return (rbg[0] << 16 | rbg[1] << 8 | rbg[2]);
}
