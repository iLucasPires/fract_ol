/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:53:33 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/10 21:54:49 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_mlx;

typedef struct s_var
{
	int		color;
	double	min[2];
	double	max[2];
	double	center[2];
	double	complex[4];
	int		max_iteration;
	int		(*fractal)(double *complex, int max_iteration);
}			t_var;

typedef struct s_data
{
	t_mlx	mlx;
	t_var	var;
}			t_data;

#endif