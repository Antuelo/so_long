/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:56:50 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/18 17:07:12 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../include/so_long.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	**read_map(const char *filename)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * 100);
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

/*c'est la divission de la funtion d'après*/
void	count_map_elements(char **map, int *player, int *exit, int *collectible)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'P')
				(*player)++;
			else if (map[i][j] == 'E')
				(*exit)++;
			else if (map[i][j] == 'C')
				(*collectible)++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				return ;
			j++;
		}
		i++;
	}
}

/*je regarde que tous les elements soient sur place*/
int	validate_map_elements(char **map)
{
	int	has_player;
	int	has_exit;
	int	has_collectible;

	has_player = 0;
	has_exit = 0;
	has_collectible = 0;
	count_map_elements(map, &has_player, &has_exit, &has_collectible);
	if (has_player != 1 || has_exit < 1 || has_collectible < 1)
		return (0);
	return (1);
}

/*me fijo que todas las lineas del mapa sean iguales*/
int	validate_map_shape(char **map)
{
	int		i;
	size_t	width;

	i = 0;
	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
