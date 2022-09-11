/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:58:57 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/11 15:12:37 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libraries.h"

int	mandelbrot(double *complex, int max_iteration)
{
	int		i;
	double	square[2];
	double	number[2];

	i = 0;
	number[R] = complex[R];
	number[I] = complex[I];
	while (++i < max_iteration)
	{
		square[I] = number[I] * number[I];
		square[R] = number[R] * number[R];
		number[I] = 2 * number[I] * number[R] + complex[I];
		number[R] = square[R] - square[I] + complex[R];
		if (square[R] + square[I] > 4)
			break ;
	}
	return (i);
}

int	julia(double *complex, int max_iteration)
{
	int		i;
	double	square[2];
	double	number[2];

	i = 0;
	number[0] = complex[0];
	number[1] = complex[1];
	while (++i < max_iteration)
	{
		square[I] = number[I] * number[I];
		square[R] = number[R] * number[R];
		number[I] = 2 * number[I] * number[R] + complex[3];
		number[R] = square[R] - square[I] + complex[2];
		if (square[R] + square[I] > 4)
			break ;
	}
	return (i);
}
