#include "../includes/libraries.h"

static int	set_color(int i, int max, int *color)
{
	int	rbg[3];

	rbg[0] = color[0] * (i / (double)max * 255);
	rbg[1] = color[1] * (i / (double)max * 0.5);
	rbg[2] = color[2] * (i / (double)max * 0.5);
	return (rbg[0] << 16 | rbg[1] << 8 | rbg[2]);
}

void	re_render(t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	draw_fractal(&data->mlx, &data->var);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
}

void	pix_put_to_img(t_mlx *mlx, t_var *var, int *axle, int result)
{
	char	*pixel;
	int		aux_pixel[3];

	aux_pixel[0] = axle[I] * mlx->line_len;
	aux_pixel[1] = axle[R] * (mlx->bpp / 8);
	pixel = mlx->addr + aux_pixel[0] + aux_pixel[1];
	if (result == var->max_interation)
		aux_pixel[2] = 0x000000;
	else
		aux_pixel[2] = set_color(result, 100, var->color);
	*(unsigned int *)pixel = aux_pixel[2];
}

int	draw_fractal(t_mlx *mlx, t_var *var)
{
	int axle[2];
	int result;
	double complex[2];

	axle[R] = 0;
	while (++axle[0] < WIDTH)
	{
		axle[I] = 0;
		while (++axle[1] < HEIGHT)
		{
			var->center[R] = var->max[R] - var->min[R];
			var->center[I] = var->max[I] - var->min[I];
			complex[R] = var->min[R] + axle[R] * var->center[R] / WIDTH;
			complex[I] = var->min[I] + axle[I] * var->center[I] / HEIGHT;
			result = var->fractal(complex, var->max_interation);
			pix_put_to_img(mlx, var, axle, result);
		}
	}
	return (0);
}