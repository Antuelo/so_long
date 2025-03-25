/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:49:41 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/25 14:33:09 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// Définitions des touches clavier
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_textures
{
	void		*wall;
	void		*floor;
	void		*player;
	void		*collect;
	void		*exit;
}				t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			win_width;
	int			win_height;
	int			tile_size;
	int			player_x;
	int			player_y;
	int			total_collectibles;
	int			collected;
	int			move;
	t_textures	img;
}				t_game;

// Fonctions principales du jeu
void			init_game(t_game *game);
int				close_game(t_game *game);
char			**read_map(const char *filename);
int				validate_map_elements(char **map);
int				validate_map_shape(char **map);
void			free_map(char **map);
void			validate_good_way(t_game *game);

// Rendu graphique
void			render_map(t_game *game);
void			load_images(t_game *game);
int				print_error(char *msg);

// mouvement du joueur et autres...
void			find_player_position(t_game *game);
int				handle_key(int keycode, t_game *game);
void			move_player(t_game *game, int new_x, int new_y);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strdup(const char *s);

#endif
