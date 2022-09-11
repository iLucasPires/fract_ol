/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 02:59:06 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/10 15:15:28 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libraries_bonus.h"

void	handle_args(int argc, char **argv, t_var *var)
{
	if (argc == 2 && !ft_strncmp(argv[1], MANDELBROT_ARG, 10))
		var->fractal = mandelbrot;
	else if (argc == 2 && !ft_strncmp(argv[1], BURNING_SHIP_ARG, 10))
		var->fractal = burningship;
	else if (argc >= 2 && !ft_strncmp(argv[1], JULIA_ARG, 10))
	{
		var->fractal = julia;
		if (argc == 4 && ft_isnumber(argv[2]) && ft_isnumber(argv[3]))
		{
			var->complex[CONST_R] = ft_atof(argv[2]);
			var->complex[CONST_I] = ft_atof(argv[3]);
		}
		else
			error_argument(MISSING_ARG);
	}
	else
		error_argument(INVALID_FRACTAL);
}
