/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:43:52 by asolomon          #+#    #+#             */
/*   Updated: 2025/06/17 20:06:14 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

ssize_t	ft_readnext(char *buffer, int fd)
{
	ssize_t	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	return (bytes);
}

ssize_t	ft_findend(char *buffer)
{
	ssize_t	i;

	i = 0;
	while (i < BUFFER_SIZE && buffer[i] && buffer[i] != '\n')
		i++;
	if (i == '\n' || (buffer[i] == 0))
		return (i);
	return (0);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	i;
	char			*final;
	ssize_t			bytes;

	final = NULL;
	if (i)
	{
		bytes = ft_findend(buffer + i);
		if (bytes)
			return (ft_cpy(buffer, i, bytes));
		else
			final = ft_cpy(buffer, i, bytes);
	}
	i = 0;
	ft_bzero(buffer, BUFFER_SIZE);
	bytes = ft_readnext(buffer, fd);
	while (bytes > 0 && i == 0)
	{
		final = ft_strjoin(final, buffer, bytes);
		bytes = ft_readnext(buffer, fd);
		i = ft_findend(buffer);
	}
	final = ft_strjoin(final, buffer, i);
	return (final);
}
