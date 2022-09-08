#include "../includes/libraries.h"

static void	types_error(int identifier)
{
	if (identifier == 1)
	{
		ft_printf("Usage for julia: ./fractol julia [real] [imag] \n");
		ft_printf("Usage for mandelbrot: ./fractol mandelbrot\n");
		ft_printf("Usage for burningship: ./fractol burningship\n");
		exit(0);
	}
	else if (identifier == 2)
	{
		ft_printf("Error: Invalid fractal or invalid number\n");
		exit(0);
	}
}

void	handle_args(int argc, char **argv, t_data *data)
{
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 11) || argv[1][0] == 'm')
			data->var.fractal = &mandelbrot;
		else if (!ft_strncmp(argv[1], "julia", 6) || argv[1][0] == 'j')
			data->var.fractal = &julia;
		else if (!ft_strncmp(argv[1], "burningship", 12) || argv[1][0] == 'b')
			data->var.fractal = &burningship;
		else
			types_error(2);
	}
	else
		types_error(1);
}