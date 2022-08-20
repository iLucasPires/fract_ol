/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:18:12 by coder             #+#    #+#             */
/*   Updated: 2022/08/20 19:18:16 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void set_fractal(t_fractal *data)
{
	data->name = strdup("mandelbrot");
	data->x = 0;
	data->y = 0;
	data->result = 0;
	data->color = 0xFFF000;
	data->cpx_x = 0;
	data->cpx_y = 0;
	data->cpx_kx = -0.52;
	data->cpx_ky = 0.57;
	data->min_r = -1.5;
	data->max_r = 1;
	data->min_im = -2;
	data->max_im = 2;
}