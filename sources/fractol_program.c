#include "../includes/libraries.h"

int	main(int argc, char **argv)
{
	t_data data;

	init_mlx(&data.mlx);
	init_var(&data.var);
	handle_args(argc, argv, &data);
	draw_fractal(&data.mlx, &data.var);
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.mlx.img, 0, 0);
	handle_hooks(&data);
	mlx_loop(data.mlx.mlx);

	return (0);
}