/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:30:00 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/18 15:25:43 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	find_player_position(t_game *game)
{
	int		x;
	int		y;

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
			else if (game->map[y][x] == 'C')
				game->total_collectibles++;
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(1, "Uso: ./so_long <mapa.ber>\n", 26);
		return (1);
	}
	game.map = read_map(argv[1]);
	if (!game.map || !validate_map_shape(game.map)
		|| !validate_map_elements(game.map))
	{
		write(1, "Error: Mapa inválido\n", 21);
		free_map(game.map);
		return (1);
	}
	write(1, "Mapa cargado con éxito:\n", 24);
	game.tile_size = 64;
	init_game(&game);
	load_images(&game);
	find_player_position(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
	return (0);
}
