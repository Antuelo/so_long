NAME = so_long

SRC = src/main.c src/map_parser.c src/init_game.c src/close_game.c \
      src/load_images.c src/render_map.c src/handle_keys.c \
      get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
      libft/ft_strlen.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
	  libft/ft_putnbr_fd.c libft/ft_strtrim.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext

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
