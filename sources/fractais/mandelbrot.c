/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:27:40 by coder             #+#    #+#             */
/*   Updated: 2022/08/20 19:17:04 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int mandelbrot(t_fractal *data)
{
	data->i = 0;
	data->result = 0;
	data->z_im = 0;
	data->z_real = 0;
	while (++data->i < MAX_INTERACTION && data->result < 4.0)
	{
		data->aux_real = ft_pow(data->z_real) - ft_pow(data->z_im) + data->cpx_x;
		data->z_im = (2 * data->z_real * data->z_im) + data->cpx_y;
		data->z_real = data->aux_real;
		data->result = ft_pow(data->z_im) + ft_pow(data->z_real); 
	}
	return (data->i);
}