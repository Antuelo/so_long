/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:25:31 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/09 19:53:32 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_game(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}
