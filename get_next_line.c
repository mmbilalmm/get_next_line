/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hal <moel-hal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:16:28 by moel-hal          #+#    #+#             */
/*   Updated: 2024/11/24 21:21:02 by moel-hal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*get_next_line(int fd)
{
	static char	next[BUFFER_SIZE + 1];
	char		*buffer;
	char		*str;
	int			bytes_reads;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	str = malloc(1);
	if (!str)
		return (free(buffer), NULL);
	str[0] = '\0';
	if (next[0] != '\0')
	{
		str = ft_strjoin(str, next, ft_strlen(next));
		next[0] = '\0';
	}
	bytes_reads = 1;
	while (bytes_reads > 0)
	{
		bytes_reads = read(fd, buffer, BUFFER_SIZE);
		if (bytes_reads == -1)
			return (free(buffer), free(str), NULL);
		buffer[bytes_reads] = '\0';
		i = 0;
		while (i < bytes_reads)
		{
			if (buffer[i] == '\n')
			{
				str = ft_strjoin(str, buffer, i + 1);
				ft_memcpy(next, buffer + i + 1, bytes_reads - i - 1);
				next[bytes_reads - i - 1] = '\0';
				return (free(buffer), str);
			}
			i++;
		}
		str = ft_strjoin(str, buffer, bytes_reads);
		if (!str)
			return (free(buffer), NULL);
	}
	if (bytes_reads == 0 && str[0] != '\0')
		return (free(buffer), str);
	return (free(str), free(buffer), NULL);
}

// next = "bonjour"
// char	*cut(char *next)
// {
// 	char	*line;
// 	int i = 0;
// 	int j = 0;
// 	while (next[i] && next[i] != '\n')
// 		line[i] = next[i++];
// 	while (next[i])
// 		next[j++] = next[++i];
// 	line[i] = 0;
// 	return (line);
// }
// char *get_next_line(int fd)
// {
// 	static char next[BUFFER_SIZE + 1] = {0};
// 	char		*line;

// 	if (strchr(next, "\n"))
// 	{
// 		line = cut(next);
// 	}
// }
// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("test.c", O_RDONLY);

// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	close(fd);

// 	return (0);
// }