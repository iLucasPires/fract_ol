/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:50:53 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/09 17:27:45 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "structs.h"

int		julia(double *complex, int max_iteration);
int		mandelbrot(double *complex, int max_iteration);
void	re_render(t_data *data);
int		handle_hooks(t_data *data);
int		draw_fractal(t_mlx *mlx, t_var *var);
void	init_mlx(t_mlx *mlx);
void	init_var(t_var *var);
void	zoom_fractal(int key, int x, int y, t_var *var);
void	handle_args(int argc, char **argv, t_var *var);
void	erro_ptr(void *ptr, const char *msg);
void	error_argument(int err);
#endif