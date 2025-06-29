/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:43:52 by asolomon          #+#    #+#             */
/*   Updated: 2025/06/17 20:52:41 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

ssize_t	ft_readnext(char *buffer, int fd)
{
	ssize_t	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0)
		return (0);
	return (bytes);
}

ssize_t	ft_findend(char *buffer)
{
	ssize_t	i;

	i = 0;
	while (i < BUFFER_SIZE && buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n' && (i == 0))
		return (1);
	if (i == BUFFER_SIZE)
		return (0);
	return (i);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	ssize_t			start;
	static ssize_t	end;
	char			*final;
	ssize_t			bytes;

	final = NULL;
	start = 0;
	if (end && end != (BUFFER_SIZE))
	{
		start = end;
		end = ft_findend(buffer + end + 1);
		if (end)
		{
			final = ft_cpy(buffer, start, end);
			end += start + 1;
			return (final);
		}
		else
			final = ft_cpy(buffer, start, end);
	}
	end = 0;
	ft_bzero(buffer, BUFFER_SIZE);
	bytes = ft_readnext(buffer, fd);
	while (bytes > 0 && end == 0)
	{
		end = ft_findend(buffer);
		if (end)
			break;
		final = ft_strjoin(final, buffer, bytes);
		bytes = ft_readnext(buffer, fd);
	}	
	final = ft_strjoin(final, buffer, (end - start));
	return (final);
}
