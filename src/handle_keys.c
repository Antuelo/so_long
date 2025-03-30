/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:57:16 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/30 11:27:46 by anoviedo         ###   ########.fr       */
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
			game->move++;
			ft_putnbr_fd(game->move, 1);
			write(1, " movements\nYOU ARE WIN MY BROTHER!\n", 35);
			close_game(game);
		}
		else
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
	game->move++;
	render_map(game);
}

int	handle_key(int keycode, t_game *game)
{
	int	before;

	before = game->move;
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
	if (before != game->move)
	{
		ft_putnbr_fd(game->move, 1);
		write(1, " movements\n", 11);
	}
	return (0);
}
