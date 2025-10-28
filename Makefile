NAME = fractol

CC		= cc
CFLAGS	= -Wall -Wextra -Werror 

SRCS = main.c init.c render.c maths_utils.c events.c burning_ship.c \
		ft_strncmp.c ft_printf.c print_formats.c

SRCS_PATH	= sources/
OBJS_PATH	= .objs/
OBJS 		= $(patsubst %.c, $(OBJS_PATH)%.o, $(SRCS))
DEPS 		= $(patsubst %.c, $(OBJS_BUILD)%.d, $(SRCS))
DEPS_FLAGS 	= -MMD -MP

HEADERS = fractol.h

MLX_DIR		=	minilibx-linux/
MLX_L 		=	-L $(MLX_DIR) -l mlx
MLX_A		=	$(MLX_DIR)libmlx.a
MLX_MAKE	=	make -C $(MLX_DIR)

DIR_INCS	= includes/	\
				$(MLX_DIR)

INCLUDES	= $(addprefix -I , $(DIR_INCS))

LIBS	= -lm $(MLX_L) -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	$(MLX_MAKE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
# 	$(CC) $(OBJS) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJS_PATH)
	@$(MLX_MAKE) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re

-include $(DEPS)
$(OBJS_PATH)%.o: $(SRCS_PATH)%.c includes/fractol.h Makefile
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@