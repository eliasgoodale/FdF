NAME = fdf

FRAM = -L minilibx -I minilibx -lmlx -framework OpenGL -framework AppKit

SRCS = src/main.c \
		src/cal_matrix.c \
		src/drawer.c \
		src/parser.c \
		src/matrix.c \
		src/helper.c \
		src/hook.c \
		src/msc.c \

LIBFT = ./libft/libft.a

MLX = ./minilibx/libmlx.a

BUILDDIR = obj

OBJS = $(patsubst %.c, %.o, *.c)

CFLAGS = -Wall -Werror -Wextra -g

NOC = \033[0m
CYAN = \033[1;36m
GREEN = \033[1;32m
YELLOW = \033[1;33m
VIOLET = \033[1;35m

all: $(LIBFT) $(MLX) $(OBJS)
	@echo "$(YELLOW)Compiling FDF...$(NOC)"
	@gcc -I include $(CFLAGS) $(OBJS) $(FRAM) -o  $(NAME) $(LIBFT)
	@echo "$(CYAN)FDF compilation:	$(GREEN)OK$(NOC)"
	@mv  -f $(OBJS) $(BUILDDIR)
	@echo "$(VIOLET)Project compiled: USAGE: ./fdf <map.fdf> $(NOC)"
$(OBJS): $(SRCS) $(BUILDDIR)
	@gcc -I include $(CFLAGS) $(SRCS) -c
$(BUILDDIR):
	@mkdir $(BUILDDIR)
$(LIBFT):
	@echo "$(YELLOW)Compiling Libft...$(NOC)"
	@cd libft && make re
	@echo "$(CYAN)Libft compilation:	$(GREEN)OK$(NOC)"
$(MLX):
	@echo "$(YELLOW)Compiling Minilibx...$(NOC)"
	@cd minilibx && make re
	@echo "$(CYAN)Minilibx compilation:	$(GREEN)OK$(NOC)"
clean: 
	@rm -rf $(BUILDDIR)
	@cd libft && make clean
	@cd minilibx && make clean
fclean: clean
	@rm -rf $(NAME)
	@cd libft && make fclean
re: fclean all
