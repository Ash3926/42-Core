/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:57:05 by asolomon          #+#    #+#             */
/*   Updated: 2025/07/02 23:05:53 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

ssize_t	find_end(t_box *new, ssize_t bytesRead)
{
	ssize_t	end;

	end = 0;
	while (end < bytesRead)
	{
		while ((new->space[end] != 0) && (new->space[end] != '\n'))
			end++;
		if (end > new->start)
			break ;
		else
			end++;
	}
	if (new->space[end] == 0 || new->space[end] == '\n')
		return (end);
	return (-1);
}

t_box	*read_nl(t_box *curr_end, int fd)
{
	t_box	*new;
	ssize_t	bytesRead;

	new = malloc(sizeof(t_box));
	if (!new)
	{
		curr_end->end = BUFFER_SIZE;
		return (curr_end);
	}
	ft_bzero(new->space, BUFFER_SIZE);
	bytesRead = read(fd, new->space, BUFFER_SIZE);
	if (bytesRead <= 0)
	{
		free(new);
		curr_end->end = BUFFER_SIZE;
		return (curr_end);
	}
	new->end = find_end(new, bytesRead);
	if (curr_end)
		curr_end->next = new;
	curr_end = new;
	return (curr_end);
}

char	*ft_join(char *str, t_box *front)
{
	t_box	*prev;
	char	*old_str;

	old_str = str;
	prev = front;
	str = ft_strjoin(old_str, front->space, front->start, front->end);
	if (old_str)
		free(old_str);
	if (front->end == -1)
	{
		front = front->next;
		free(prev);
	}
	else
	{
		front->start = front->end + 1;
		front->end = find_end(front, BUFFER_SIZE);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static t_box	*front;
	char	*str;
	t_box	*curr_end;

	str = NULL;
	if (fd < 0)
		return (NULL);
	if (!front)
		front = read_nl(front, fd);
	curr_end = front;
	while (curr_end->end == -1)
		read_nl(curr_end, fd);
	while (front != curr_end)
		str = ft_join(str, front);
	str = ft_join(str, front);
	return (str);
}
