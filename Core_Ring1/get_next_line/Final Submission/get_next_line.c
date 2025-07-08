/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:43:52 by asolomon          #+#    #+#             */
/*   Updated: 2025/07/08 15:55:35 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

ssize_t	ft_readnext(char *buffer, int fd)
{
	ssize_t	bytes;

	buffer = ft_bzero(buffer, BUFFER_SIZE);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (0);
	return (bytes);
}

ssize_t	ft_findend(char *buffer, ssize_t end, ssize_t bytes)
{
	end += 1;
	while (end < bytes && buffer[end] && buffer[end] != '\n')
		end++;
	if (end == bytes)
		return (-1);
	return (end);
}

ssize_t	*pointer_assign(ssize_t pointers[3], char *buffer, int fd, int flag)
{
	if (flag == 0)
	{
		pointers[0] = pointers[1];
		pointers[1] = ft_findend(buffer, pointers[1], pointers[2]);
	}
	if (flag == 1)
	{
		pointers[2] = ft_readnext(buffer, fd);
		if (pointers[2] <= 0)
			return (NULL);
		pointers[1] = ft_findend(buffer, -1, pointers[2]);
	}
	if (flag == 2)
	{
		pointers[2] = ft_readnext(buffer, fd);
		pointers[1] = ft_findend(buffer, pointers[1], pointers[2]);
	}
	return (pointers);
}

char	*get_next_line(int fd)
{
	static char				buffer[BUFFER_SIZE + 1];
	static ssize_t			pointers[3];
	char					*final;

	final = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (pointers[2] && pointers[1] != -1 && pointers[1] < (pointers[2] - 1))
	{
		pointer_assign(pointers, buffer, fd, 0);
		final = ft_cpy(buffer, pointers[0], pointers[1], pointers[2]);
		if (pointers[1] != -1)
			return (final);
	}
	pointer_assign(pointers, buffer, fd, 1);
	if (pointers[2] <= 0)
		return (final);
	while (pointers[2] > 0 && pointers[1] == -1)
	{
		final = ft_strjoin(final, buffer, pointers[2]);
		pointer_assign(pointers, buffer, fd, 2);
	}
	return (ft_strjoin(final, buffer, (pointers[1] + 1)));
}
