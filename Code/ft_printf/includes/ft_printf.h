/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:33:01 by lpires-n          #+#    #+#             */
/*   Updated: 2022/07/01 07:10:01 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_BASE "0123456789abcdef"
# define DEC_BASE "0123456789"

typedef struct s_node
{
	int				size;
	char			*value;
	struct s_node	*next;
}					t_node;

typedef struct s_types
{
	int				len;
	int				index;
	int				start;
	char			*aux;
	char			*string;

}					t_types;

// # PROTOTYPES #
int					ft_printf(const char *format, ...);

//## CONVERSIONS ##
size_t				ft_ptoi(void *pointer);
char				*ft_itop(unsigned long int number);
char				*ft_itobase(unsigned int number, int base, char *type_base);

// ## HANDLES NODES ##
void				free_all(t_node **list);
int					printf_node(t_node **list);
void				append_node_back(t_node **list, char *value, int size);

// ## HANDLE_TYPES ##
void				add_void_node(t_node **list, void *pointer);
void				add_string_node(t_node **list, char *string);
void				add_char_node(t_node **list, char character);
void				add_hex_node(t_node **list, size_t number, char type);
void				add_number_node(t_node **list, long int number, char type);

#endif