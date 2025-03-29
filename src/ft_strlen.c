/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:24:58 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/29 12:14:55 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *h)
{
	int	i;

	i = 0;
	while (h[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*a;

	a = "hola";
	printf("la plabra \"hola\" tiene %d caracteres \n", ft_strlen(a));
}
*/
