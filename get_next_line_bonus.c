/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:45:18 by belinore          #+#    #+#             */
/*   Updated: 2024/12/04 14:08:04 by belinore         ###   ########.fr       */
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
/*
int	main(void)
{
	int	file_des;
	int	file_des2;
	char	*next_line;

	file_des = open ("test_text", O_RDONLY);
	if (file_des < 0)
		return (-1);
	file_des2 = 0;
	next_line = get_next_line(file_des2);
	printf("Line1_terminal: %s\n", next_line);
	free(next_line);
	next_line = get_next_line(file_des);
	printf("Line1: %s", next_line);
	free(next_line);
	next_line = get_next_line(file_des2);
	printf("Line2_terminal: %s\n", next_line);
	free(next_line);
	next_line = get_next_line(file_des);
	printf("Line2: %s", next_line);
	free(next_line);
	next_line = get_next_line(file_des);
	printf("Line3: %s", next_line);
	free(next_line);
	next_line = get_next_line(file_des);
	printf("Line4: %s", next_line);
	free(next_line);
	next_line = get_next_line(file_des);
	printf("Line5: %s", next_line);
	if (close (file_des) < 0)
		return (-1);
	return (0);
}*/
