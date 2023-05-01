NAME = so_long

SRCS = main.c\
	ft_putnbr.c\
	get_next_line.c\
	get_next_line_utils.c\
	moves.c\
	readmap.c\
	readmap2.c\
	split.c\
	utils.c\
	utils2.c\
	valid_path.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all