/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_program_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:59:05 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/09 18:59:33 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	handle_args(argc, argv, &data.var);
	init_var(&data.var);
	init_mlx(&data.mlx);
	draw_fractal(&data.mlx, &data.var);
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.mlx.img, 0, 0);
	handle_hooks(&data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
