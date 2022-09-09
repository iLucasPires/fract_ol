NAME =		fractol
HEADER =	./includes
SRC_DIR =	./sources
OBJ_DIR =	./objects
BONUS_DIR =	./bonus
LIBFT_DIR =	./libft_printf
SRC_FILES =	fractol_program.c	create_data.c	draw_fractals.c	errors_warnings.c\
			handle_arguments.c	handle_hooks.c	transform_fractal.c	types_fractals.c

SRC_FILES = fractol_program_bonus.c	create_data_bonus.c	draw_fractals_bonus.c	errors_warnings_bonus.c\
			handle_arguments_bonus.c	handle_hooks_bonus.c	transform_fractal_bonus.c	types_fractals_bonus.c

LIBFT =		$(addprefix $(LIBFT_DIR)/, libftprintf.a)
SRC =		$(addprefix $(SRC_DIR)/, $(SRC_FILES))

BONUS =		$(addprefix $(BONUS_DIR)/, $(SRC_FILES:.c=.o))

CFLAGS =		-g3 -lX11 -lXext -lmlx -lm -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	clang $(OBJ) $(LIBFT) $(CFLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	mkdir -p $(OBJ_DIR)
	clang -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	clang -c $< -o $@

bonus: $(BONUS) $(LIBFT)
	clang $(BONUS) $(LIBFT) $(CFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

