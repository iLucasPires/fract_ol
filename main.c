/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:41:54 by lpires-n          #+#    #+#             */
/*   Updated: 2022/08/20 20:10:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"


void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_fractal(t_mlx *img, t_fractal *data, int (*fractal)(t_fractal *data))
{
	while (++data->y < HEIGHT)
	{
		while (++data->x < WIDTH)
		{
			data->cpx_x = find_c(data->min_r, data->max_r, data->x, WIDTH);
			data->cpx_y = find_c(data->min_im, data->max_im, data->y, HEIGHT);
			data->result = fractal(data);
			data->color = data->color + data->result * data->result;
			if (data->result == 100)
				my_mlx_pixel_put(img, data->x, data->y, 0x000000);
			else
				my_mlx_pixel_put(img, data->x, data->y, 0x9400D3 + data->result * 100);
		}
		data->x = 0;
	}
}

void init(t_fractal *data, t_mlx *img)
{
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "my_fractol");
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	draw_fractal(img, data, mandelbrot);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_loop(img->mlx);
}

int main(void)
{
	t_mlx	img;
	t_fractal data; 

	set_fractal(&data);
	init(&data, &img);

	return 0;
}
