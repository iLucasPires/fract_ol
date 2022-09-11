/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:50:53 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/10 21:34:05 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_BONUS_H
# define FUNCTIONS_BONUS_H
# include "structs_bonus.h"

int		julia(double *complex, int max_iteration);
int		mandelbrot(double *complex, int max_iteration);
int		burningship(double *complex, int max_iteration);
void	re_render(t_data *data);
int		handle_hooks(t_data *data);
int		draw_fractal(t_mlx *mlx, t_var *var);
void	init_mlx(t_mlx *mlx);
void	init_var(t_var *var);
int		move_fractal(int key, t_var *var);
void	zoom_fractal(int key, int x, int y, t_var *var);
void	handle_args(int argc, char **argv, t_var *var);
void	erro_ptr(void *ptr, const char *msg);
void	error_argument(int err);
int		set_color(int i, t_var *var);
void	menu(t_mlx *mlx);
void	init_windows(t_mlx *mlx);
void	int_img(t_mlx *mlx);
#endif