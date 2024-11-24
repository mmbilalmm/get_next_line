/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-hal <moel-hal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:18:06 by moel-hal          #+#    #+#             */
/*   Updated: 2024/11/24 20:13:18 by moel-hal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buffer, int buffer_size)
{
	int		i;
	int		j;
	char	*new_str;

	new_str = malloc(sizeof(char) * (ft_strlen(str) + buffer_size + 1));
	if (!new_str)
		return (free(str), NULL);
	i = 0;
	j = 0;
	while (str && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (j < buffer_size)
	{
		new_str[i + j] = buffer[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (free(str), new_str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (dest == NULL || src == NULL || n == 0)
		return (dest);
	d = (char *)dest;
	s = (const char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
