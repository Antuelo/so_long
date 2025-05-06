/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <anoviedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:25:31 by anoviedo          #+#    #+#             */
/*   Updated: 2025/05/06 12:58:55 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->img.collect);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.player);
	mlx_destroy_image(game->mlx, game->img.wall);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	print_error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	return (0);
}
