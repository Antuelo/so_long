/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <anoviedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:32:14 by anoviedo          #+#    #+#             */
/*   Updated: 2025/04/12 15:01:03 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_images(t_game *game)
{
	int	size;

	size = game->tile_size;
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&size, &size);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&size, &size);
	game->img.player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&size, &size);
	game->img.collect = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm",
			&size, &size);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&size, &size);
	if (!game->img.wall || !game->img.floor || !game->img.player
		|| !game->img.collect || !game->img.exit)
	{
		write(2, "Error: images could not be loaded\n", 34);
		exit(1);
	}
}
