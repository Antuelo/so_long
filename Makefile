NAME = so_long
SRC = src/main.c src/map_parser.c \
      get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
      libft/ft_strlen.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
