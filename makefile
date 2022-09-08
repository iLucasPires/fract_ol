NAME =		fractol.a
HEADER =	./includes
SRC_DIR =	./sources
OBJ_DIR =	./objects
LIBFT_DIR =	./libft_printf
SRC_FILES =	fractol_program.c	create_data.c	draw_fractals.c	\
			handle_arguments.c	handle_hooks.c	transform_fractal.c	types_fractals.c
LIBFT =		$(addprefix $(LIBFT_DIR)/, libftprintf.a)
SRC =		$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ =		$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

CFLAGS =		-g3 -lX11 -lXext -lmlx -lm -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	clang $(OBJ) $(LIBFT) $(CFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	mkdir -p $(OBJ_DIR)
	clang -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

