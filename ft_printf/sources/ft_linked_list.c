/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 06:58:03 by lpires-n          #+#    #+#             */
/*   Updated: 2022/07/01 07:04:38 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	append_node_back(t_node **list, char *value, int size)
{
	t_node	*aux;
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->value = ft_strdup(value);
	node->size = size;
	node->next = NULL;
	if (!*list)
		*list = node;
	else
	{
		aux = *list;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = node;
	}
}

void	free_all(t_node **list)
{
	t_node	*aux;
	t_node	*to_free;

	aux = list[0];
	while (aux != NULL)
	{
		to_free = aux;
		aux = aux->next;
		free(to_free->value);
		free(to_free);
	}
}

int	printf_node(t_node **list)
{
	t_node	*aux;
	int		size;

	size = 0;
	aux = *list;
	while (aux != NULL)
	{
		size += aux->size;
		write(1, aux->value, aux->size);
		aux = aux->next;
	}
	free_all(list);
	return (size);
}
