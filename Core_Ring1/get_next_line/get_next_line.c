/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:49:36 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/28 19:48:56 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

ssize_t	ft_readnext(char *buf, int fd)
{
	ssize_t	bytes;

	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buf)
		return (0);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes > 0)
		return (bytes);
	return (0);
}

ssize_t	ft_findend(char *buf)
{
	ssize_t	i;

	i = 0;
	while (buf[i] && buf[i] != '\n' && i < BUFFER_SIZE)
	{
		i++;
	}
	if (buf[i] == '\n')
		return (i);
	else
		return (0);
}

char	*get_next_line(int fd)
{
	char	*main;
	char	*buffer;
	ssize_t	bytes;
	ssize_t i;

	main = NULL;
	if (fd < 0)
		return (NULL);
	bytes = ft_readnext(buffer, fd);
	if (bytes < 0)
		return (NULL);
	i = ft_findend(buffer);
	while (i != 0)
	{
		
	}
	return (ft_strjoin(main, buf, i)); //ft_strjoin to be edited to max add i bytes from buf