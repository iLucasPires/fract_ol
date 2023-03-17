/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:58:52 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/11 19:14:29 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libraries.h"

void	zoom_fractal(int key, t_var *var)
{
	if (key == 4)
	{
		var->min[R] += var->center[R] / 10;
		var->max[R] -= var->center[R] / 10;
		var->min[I] += var->center[I] / 10;
		var->max[I] -= var->center[I] / 10;
		var->max_iteration += 10;
	}
	else if (key == 5)
	{
		var->min[R] -= var->center[R] / 10;
		var->max[R] += var->center[R] / 10;
		var->min[I] -= var->center[I] / 10;
		var->max[I] += var->center[I] / 10;
		if (var->max_iteration > 100)
			var->max_iteration -= 10;
	}
}

int	set_color(int i, t_var *var)
{
	int	rbg[3];

	rbg[0] = sin(0.1 * i + 5) * 127 + 128;
	rbg[1] = sin(0.1 * i + 6) * 127 + 128;
	rbg[2] = sin(0.1 * i + 7) * 127 + 128;
	return (rbg[0] << 16 | rbg[1] << 8 | rbg[2]);
}
