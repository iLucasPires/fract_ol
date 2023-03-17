CC = gcc
NAME =	libftprintf.a
FLAGS =	-Wall -Wextra -Werror

SRCS =	./sources/ft_conversion.c \
		./sources/ft_printf.c \
		./sources/ft_handle_types.c \
		./sources/ft_linked_list.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@mv ./libft/libft.a ./$(NAME)
	@ar -rcs $(NAME) $(OBJS) 

%.o : %.c ./includes/ft_printf.h
	@$(CC) $(FLAGS) -c $< -o $@ -I ./includes

clean:
	@rm -rf $(OBJS)
	@rm -rf ./libft/*.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all 

.PHONY: all fclean clean re bonus