/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:59:05 by lpires-n          #+#    #+#             */
/*   Updated: 2022/09/11 14:53:16 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libraries.h"

int	main(int argc, char **argv)
{
	t_data	data;

	handle_args(argc, argv, &data.var);
	init_var(&data.var);
	init_mlx(&data.mlx);
	handle_hooks(&data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
