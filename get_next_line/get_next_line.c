/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:43:41 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/09 17:02:38 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_and_concatenate(int fd, char **buffer)
{
	char	bufferead[BUFFER_SIZE + 1];
	char	*temp;
	size_t	fdsize;

	fdsize = read(fd, bufferead, BUFFER_SIZE);
	if (fdsize <= 0)
	{
		if (fdsize == 0)
			return (0);
		return (-1);
	}
	bufferead[fdsize] = '\0';
	temp = *buffer;
	*buffer = ft_strjoin(*buffer, bufferead);
	if (!buffer)
		return (-1);
	free(temp);
	return (fdsize);
}

char	*read_and_append(int fd, char **buffer)
{
	if (!*buffer)
		*buffer = ft_calloc(1, 1);
	while (!ft_strchr(*buffer, '\n'))
	{
		if (read_and_concatenate(fd, buffer) <= 0)
			return (NULL);
	}
	return (*buffer);
}

char	*extract_line(char *buffer)
{
	size_t	i;
	char	*line;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

void	trim_buffer(char **buffer)
{
	size_t	pos;
	size_t	i;
	char	*temp;

	pos = 0;
	while ((*buffer)[pos] != '\n' && (*buffer)[pos] != '\0')
		pos++;
	if ((*buffer)[pos] == '\0')
	{
		if (pos > 0)
			return ;
		free(*buffer);
		*buffer = NULL;
		return ;
	}
	pos++;
	temp = *buffer;
	*buffer = (char *)ft_calloc((gnl_strlen(temp) - pos + 1), sizeof(char));
	if (!*buffer)
		return ;
	i = 0;
	while (temp[pos])
		(*buffer)[i++] = temp[pos++];
	(*buffer)[i] = '\0';
	free(temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_and_append(fd, &buffer) == NULL)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = extract_line(buffer);
	if (line == NULL)
		return (NULL);
	trim_buffer(&buffer);
	if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
/*
void	run_test(char *filename)
{
	int		fd;
	char	*line;
	int		line_number;

	line_number = 1;
	printf("Reading file: %s\n", filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return ;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", line_number++, line);
		free(line);
	}
	close(fd);
	printf("\n--- End of %s ---\n\n", filename);
}

int	main(void)
{
	// List of test files to check different cases
	char *filenames[] = {
		"empty.txt",
		"single_line.txt",
		"multi_line.txt",
		"no_newline_end.txt",
		"long_line.txt"
	};
	for (int i = 0; i < 5; i++)
		run_test(filenames[i]);
	return (0);
}
*/
