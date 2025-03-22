/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:16:28 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/22 15:07:48 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx_int.h"

void	init_game(t_game *game)
{
	int	width;
	int	height;

	width = (ft_strlen(game->map[0]) * game->tile_size);
	height = 0;
	while (game->map[height])
		height++;
	height *= game->tile_size;
	game->win_width = width;
	game->win_height = height;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height,
			"so_long");
}
