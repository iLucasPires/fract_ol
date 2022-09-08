#include "../includes/structs.h"
#include "../includes/functions.h"
#include "../includes/libraries.h"

void init_var(t_var *var)
{
	var->max_interation = 100; 
	var->min[R] = -1.5;
	var->min[I] = -1.5;
	var->max[R] = 1.5;
	var->max[I] = 1.5;
	var->complex[R] = 0;
	var->complex[I] = 0;
	var->color[0] = 255;
	var->color[1] = 255;
	var->color[2] = 255;
}

void init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Fractol");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_len, &mlx->endian);
}