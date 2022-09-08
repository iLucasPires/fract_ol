#include "../includes/libraries.h"

int	move_fractal(int key, t_var *var)
{
	if (key == UP)
	{
		var->min[I] -= var->center[I] / 100;
		var->max[I] -= var->center[I] / 100;
	}
	else if (key == DOWN)
	{
		var->min[I] += var->center[I] / 100;
		var->max[I] += var->center[I] / 100;
	}
	else if (key == LEFT)
	{
		var->min[R] -= var->center[R] / 100;
		var->max[R] -= var->center[R] / 100;
	}
	else if (key == RIGHT)
	{
		var->min[R] += var->center[R] / 100;
		var->max[R] += var->center[R] / 100;
	}
	return (0);
}

void	zoom_fractal(int key, int x, int y, t_var *var)
{
	if (key == 4)
	{
		var->min[R] += var->center[R] * (x / (double)WIDTH) / 10;
		var->max[R] -= var->center[R] * (1 - x / (double)WIDTH) / 10;
		var->min[I] += var->center[I] * (y / (double)HEIGHT) / 10;
		var->max[I] -= var->center[I] * (1 - y / (double)HEIGHT) / 10;
		var->max_interation += 10;
	}
	else if (key == 5)
	{
		var->min[R] -= var->center[R] * (1 - x / (double)WIDTH) / 10;
		var->max[R] += var->center[R] * (x / (double)WIDTH) / 10;
		var->min[I] -= var->center[I] * (1 - y / (double)HEIGHT) / 10;
		var->max[I] += var->center[I] * (y / (double)HEIGHT) / 10;
		if (var->max_interation > 100)
			var->max_interation -= 10;
	}
}