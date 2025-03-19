/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:57:16 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/18 17:41:56 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collected == game->total_collectibles)
		{
			write(1, "YOU ARE WIN MY BROTHER!\n", 24);
			close_game(game);
		}
		return ;
	}
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	render_map(game);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}
