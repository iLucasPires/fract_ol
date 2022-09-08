#include "../includes/libraries.h"


void change_color(t_data *data)
{
	data->var.color[0] = rand() % 255;
	data->var.color[1] = rand() % 255;
	data->var.color[2] = rand() % 255;
}

static int handle_mouse(int key, int x, int y, t_data *data)
{
	if (key == 4 || key == 5)
	{
		zoom_fractal(key, x, y, &data->var);
		re_render(data);
	}
	else if ( key == 1)
	{
		change_color(data);
		re_render(data);
	}
	
	

	return (0);
}

static int handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	mlx_destroy_display(data->mlx.mlx);
	free(data->mlx.mlx);
	exit(0);
}


static int handle_key(int key, t_data *data)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
	{
		move_fractal(key, &data->var);
		re_render(data);
	}
	else if (key == ESC)
		handle_close(data);
	return (0);
}


int handle_hooks(t_data *data)
{
	mlx_hook(data->mlx.win, 17, 0, handle_close, data);
	mlx_mouse_hook(data->mlx.win, handle_mouse, data);
	mlx_key_hook(data->mlx.win, handle_key, data);
	return (0);
}