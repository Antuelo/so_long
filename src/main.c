/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <anoviedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:30:00 by anoviedo          #+#    #+#             */
/*   Updated: 2025/05/06 12:24:48 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	compter_collectibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->total_collectibles++;
			x++;
		}
		y++;
	}
}

void	find_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->total_collectibles = 0;
	game->collected = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	validate_map(char **map, t_game *game)
{
	if (!map)
		return (print_error("problem reading map\n"));
	if (!validate_map_elements(map))
		return (0);
	if (!validate_map_shape(map))
		return (0);
	find_player_position(game);
	validate_good_way(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	game.map = read_map(argv[1]);
	if (!validate_map(game.map, &game))
	{
		free_map(game.map);
		return (1);
	}
	game.move = 0;
	game.tile_size = 64;
	init_game(&game);
	load_images(&game);
	compter_collectibles(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
	return (0);
}
