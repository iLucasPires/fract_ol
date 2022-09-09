#ifndef BONUS_H
# define BONUS_H
# include "../includes/libraries.h"


# define BURNING_SHIP_ARG "burningship"
void	zoom_fractal(int key, int x, int y, t_var *var);
int		burningship(double *complex, int max_iteration);
int	move_fractal(int key, t_var *var);
#endif