/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:30:00 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/09 14:28:50 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
	{
		printf("Uso: ./so_long <mapa.ber>\n");
		return (1);
	}
	map = read_map(argv[1]);
	if (!map || !validate_map_shape(map) || !validate_map_elements(map))
	{
		printf("Error: Mapa inválido\n");
		free_map(map);
		return (1);
	}
	printf("Mapa cargado con éxito:\n");
	print_map(map);
	free_map(map);
	return (0);
}
