/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:28:21 by coder             #+#    #+#             */
/*   Updated: 2022/08/20 19:16:47 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int julia(t_fractal *data)
{
	data->i = 0;
	data->result = 0;
	data->z_im = data->cpx_y;
	data->z_real = data->cpx_x;
	while (++data->i < MAX_INTERACTION && data->result < 4.0)
	{
		data->aux_real = ft_pow(data->z_real) - ft_pow(data->z_im) + data->cpx_kx;
		data->z_im = (2 * data->z_real * data->z_im) + data->cpx_ky;
		data->z_real = data->aux_real;
		data->result = ft_pow(data->z_im) + ft_pow(data->z_real);
	}
	return (data->i);
}
