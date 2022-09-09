/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:58:52 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/09 17:18:56 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libraries.h"

void	zoom_fractal(int key, int x, int y, t_var *var)
{
	if (key == 4)
	{
		var->min[R] += var->center[R] / 10;
		var->max[R] -= var->center[R] / 10;
		var->min[I] += var->center[I] / 10;
		var->max[I] -= var->center[I] / 10;
		var->max_interation += 10;
	}
	else if (key == 5)
	{
		var->min[R] -= var->center[R] / 10;
		var->max[R] += var->center[R] / 10;
		var->min[I] -= var->center[I] / 10;
		var->max[I] += var->center[I] / 10;
		if (var->max_interation > 100)
			var->max_interation -= 10;
	}
}
