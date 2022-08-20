NAME =	main.a
SRC =	main.c	\
		sources/utils.c	\
		sources/fractais/*.c	\
		sources/config/set_fractal.c

HEADER = ./includes


$(NAME): $(SRC) $(HEADER)
	cc $(SRC) -g3 -lX11 -lXext -lmlx -o $(NAME) -I $(HEADER)

