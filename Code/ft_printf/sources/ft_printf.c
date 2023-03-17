/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:30:34 by lpires-n          #+#    #+#             */
/*   Updated: 2022/07/01 07:10:31 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	verify_type(char format, t_node **list, va_list args)
{
	if (format == 's')
		add_string_node(list, va_arg(args, char *));
	else if (format == 'i' || format == 'd')
		add_number_node(list, va_arg(args, int), format);
	else if (format == 'x' || format == 'X')
		add_hex_node(list, va_arg(args, int), format);
	else if (format == 'u')
		add_number_node(list, va_arg(args, int), format);
	else if (format == 'p')
		add_void_node(list, va_arg(args, void *));
	else if (format == 'c')
		add_char_node(list, va_arg(args, int));
	else if (format == '%')
		add_char_node(list, '%');
}

static void	aux_printf(t_node **list, const char *format, va_list args)
{
	t_types	var;

	var.index = 0;
	var.start = 0;
	while ((int)ft_strlen(format) >= var.index)
	{
		if (format[var.index] == '%' || format[var.index] == '\0')
		{
			var.len = var.index - var.start;
			var.string = ft_substr(format, var.start, var.len);
			append_node_back(list, var.string, var.len);
			if (format[var.index] != '\0')
			{
				var.index = var.index + 1;
				verify_type(format[var.index], list, args);
				var.start = var.index + 1;
			}
			free(var.string);
		}
		var.index = var.index + 1;
	}
}

int	ft_printf(const char *format, ...)
{
	t_node	*list;
	va_list	list_args;

	list = NULL;
	va_start(list_args, format);
	aux_printf(&list, format, list_args);
	va_end(list_args);
	return (printf_node(&list));
}
