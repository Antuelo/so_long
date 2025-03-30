/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:45:37 by antuel            #+#    #+#             */
/*   Updated: 2025/03/09 17:02:32 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*copy(char const *s1, char const *s2, char *str)
{
	size_t	j;
	size_t	i;

	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		str[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
		j++;
	j += i;
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (str == NULL)
		return (NULL);
	str = copy(s1, s2, str);
	if (!str)
		return (NULL);
	return (str);
}

size_t	gnl_strlen(const char *h)
{
	int	i;

	i = 0;
	if (!h)
		return (0);
	while (h[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	mem = (char *)malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		mem[i] = '\0';
		i++;
	}
	return ((void *)mem);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	size_t			i;

	uc = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			return ((char *)&s[i]);
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
