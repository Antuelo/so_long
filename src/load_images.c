/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:32:14 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/09 19:50:36 by anoviedo         ###   ########.fr       */
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
		write(2, "Error: No se pudieron cargar las imágenes\n", 42);
		exit(1);
	}
}
