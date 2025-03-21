/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:41:50 by belinore          #+#    #+#             */
/*   Updated: 2025/03/21 18:20:27 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	strjoin_cpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dst[i] = '\n';
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*string;
	size_t		len;
	size_t		i;

	i = 0;
	len = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 != NULL)
		len += ft_strlen_nl(s1);
	if (s2 != NULL)
		len += ft_strlen_nl(s2);
	string = malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (free(s1), NULL);
	if (s1 != NULL)
		i = strjoin_cpy(string, s1);
	if (s2 != NULL)
		strjoin_cpy(&string[i], s2);
	return (free(s1), string);
}

size_t	ft_strlen_nl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*move_buffer_up(char *dst, char *src)
{
	int	i;

	if (src == NULL || dst == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
