/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:34:09 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/09 19:49:47 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*get_tile_image(t_game *game, char tile)
{
	if (tile == '1')
		return (game->img.wall);
	else if (tile == '0')
		return (game->img.floor);
	else if (tile == 'P')
		return (game->img.player);
	else if (tile == 'C')
		return (game->img.collect);
	else if (tile == 'E')
		return (game->img.exit);
	return (NULL);
}

void	render_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			img = get_tile_image(game, game->map[y][x]);
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img, x
					* game->tile_size, y * game->tile_size);
			x++;
		}
		y++;
	}
}
