/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:59:05 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/10 21:48:11 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libraries.h"

int	main(int argc, char **argv)
{
	t_data	data;

	handle_args(argc, argv, &data.var);
	init_var(&data.var);
	init_mlx(&data.mlx);
	re_render(&data);
	handle_hooks(&data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
