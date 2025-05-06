/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_good_way.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <anoviedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:36:57 by anoviedo          #+#    #+#             */
/*   Updated: 2025/04/12 14:24:31 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**copy_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	if (map[y + 1])
		flood_fill(map, y + 1, x);
	if (y > 0)
		flood_fill(map, y - 1, x);
	if (map[y][x + 1])
		flood_fill(map, y, x + 1);
	if (x > 0)
		flood_fill(map, y, x - 1);
}

int	has_unreachable_elements(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	validate_path(char **map, int y, int x)
{
	char	**copy;

	copy = copy_map(map);
	if (!copy)
		return (print_error("Error coping the map, my brother\n"));
	flood_fill(copy, y, x);
	if (has_unreachable_elements(copy))
	{
		free_map(copy);
		return (print_error(\
			"No way possible, I don't want to stay locked up!!\n"));
	}
	free_map(copy);
	return (1);
}

void	validate_good_way(t_game *game)
{
	if (!validate_path(game->map, game->player_y, game->player_x))
	{
		free_map(game->map);
		exit(1);
	}
}
