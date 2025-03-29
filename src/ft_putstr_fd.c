/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:44:42 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/29 12:14:26 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
		i++;
	write (fd, s, i);
}
/*
imprime string , especificando "fd"
int	main(void)
{
	char	*world = "hola";

	ft_putstr_fd(world, 1);
}
*/
