
NAME = fdf

FRAM = -L minilibx -I minilibx -lmlx -framework OpenGL -framework AppKit -g

SRCS = drawer.c parser.c main.c

LIBFT = ./libft/libft.a

OBJS = $(patsubst %.c, %.o, $(SRCS))

all:
	gcc -I fdf.h  -g $(SRCS) -c 
	gcc -I fdf.h  -g $(OBJS) $(FRAM) -o  $(NAME) $(LIBFT)

fclean: 
		rm -rf $(NAME)
