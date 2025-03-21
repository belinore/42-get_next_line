/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:45:18 by belinore          #+#    #+#             */
/*   Updated: 2025/03/21 18:19:05 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*next_line;
	ssize_t		bytes_read;

	next_line = NULL;
	while (fd >= 0 && fd <= FD_MAX && BUFFER_SIZE > 0)
	{
		if (buffer[0] == '\0')
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read == 0)
				return (next_line);
			if (bytes_read < 0)
				return (free(next_line), NULL);
			buffer[bytes_read] = '\0';
		}
		next_line = ft_strjoin(next_line, buffer);
		if (next_line == NULL)
			return (NULL);
		move_buffer_up(&buffer[0], &buffer[ft_strlen_nl(buffer)]);
		if (next_line[ft_strlen_nl(next_line) - 1] == '\n')
			return (next_line);
	}
	return (next_line);
}
