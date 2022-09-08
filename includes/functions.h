#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structs.h"

// fractais
int		julia(double *complex, int max_iteration);
int		mandelbrot(double *complex, int max_iteration);
int		burningship(double *complex, int max_iteration);
void	re_render(t_data *data);
int		handle_hooks(t_data *data);
void	create_data(t_data *data);
int		draw_fractal(t_mlx *mlx, t_var *var);
void	pix_put_to_img(t_mlx *mlx, t_var *var, int *axle, int result);
void	init_mlx(t_mlx *mlx);
void	init_var(t_var *var);

void	zoom_fractal(int key, int x, int y, t_var *var);

// handle arguments
void	handle_args(int argc, char **argv, t_data *data);
int		move_fractal(int key, t_var *var);

#endif