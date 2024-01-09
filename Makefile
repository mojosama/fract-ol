NAME = fractol.a

CC = cc

CFLAGS = -Wall -Wextra -Werror 

HEADERS = fractol.h mlx.h

SRCS = main.c init.c render.c maths_utils.c events.c ft_strncmp.c ft_printf.c print_formats.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re