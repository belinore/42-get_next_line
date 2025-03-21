/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:45:18 by belinore          #+#    #+#             */
/*   Updated: 2025/03/21 18:22:29 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX][BUFFER_SIZE + 1];
	char		*next_line;
	ssize_t		bytes_read;

	next_line = NULL;
	while (fd >= 0 && fd <= FD_MAX && BUFFER_SIZE > 0)
	{
		if (buffer[fd][0] == '\0')
		{
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
			if (bytes_read == 0)
				return (next_line);
			if (bytes_read < 0)
				return (free(next_line), NULL);
			buffer[fd][bytes_read] = '\0';
		}
		next_line = ft_strjoin(next_line, buffer[fd]);
		if (next_line == NULL)
			return (NULL);
		move_buffer_up(&buffer[fd][0], &buffer[fd][ft_strlen_nl(buffer[fd])]);
		if (next_line[ft_strlen_nl(next_line) - 1] == '\n')
			return (next_line);
	}
	return (next_line);
}
