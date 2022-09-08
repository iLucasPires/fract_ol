/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 06:59:11 by lpires-n          #+#    #+#             */
/*   Updated: 2022/07/01 06:59:47 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_cont_digits(size_t number, int base)
{
	int	counter;

	counter = 1;
	if (number == 0)
		return (1);
	while (number / base > 0)
	{
		counter = counter + 1;
		number = number / base;
	}
	return (counter);
}

char	*ft_itobase(unsigned int number, int base, char *type_base)
{
	t_types	var;

	var.aux = ft_strdup(type_base);
	var.len = ft_cont_digits(number, base);
	var.string = malloc(sizeof(char) * (var.len + 1));
	var.string[var.len] = '\0';
	while (var.len)
	{
		var.len = var.len - 1;
		var.string[var.len] = var.aux[number % base];
		number = number / base;
	}
	free(var.aux);
	return (var.string);
}

char	*ft_itop(size_t number)
{
	t_types	var;

	var.aux = ft_strdup(HEX_BASE);
	var.len = ft_cont_digits(number, 16);
	var.string = malloc(sizeof(char) * (var.len + 1));
	var.string[var.len] = '\0';
	while (var.len)
	{
		var.len = var.len - 1;
		var.string[var.len] = var.aux[number % 16];
		number = number / 16;
	}
	free(var.aux);
	return (var.string);
}
