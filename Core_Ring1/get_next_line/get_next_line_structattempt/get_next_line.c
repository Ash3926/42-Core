/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:57:05 by asolomon          #+#    #+#             */
/*   Updated: 2025/07/02 19:32:13 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

ssize_t	find_end(t_box *new, ssize_t bytesRead)
{
	ssize_t	end;

	end = 0;
	while (end < bytesRead)
	{
		while ((new.space[end] != 0) && (new.space[end] != '\n'))
			end++;
		if (end > new.start)
			break ;
	}
	if (new.space[end] == 0 || new.space[end] == '\n')
		return (end);
	return (-1);
}

void	read_nl(t_box *curr_end, int fd)
{
	t_box	*new;
	ssize_t	bytesRead;

	new = malloc(sizeof(t_box));
	if (!new)
	{
		curr_end.end = BUFFER_SIZE;
		return ;
	}
	bytesRead = read(fd, new.space, BUFFER_SIZE);
	if (bytesRead <= 0)
	{
		free(new);
		curr_end.end = BUFFER_SIZE;
		return ;
	}
	new.end = find_end(new, bytesRead);
	curr_end.next = new;
	curr_end = new;
}

void	ft_join(char *str, t_box *front)
{
	t_box	*prev;
	char	*old_str;

	old_str = str;
	prev = front;
	str = ft_strjoin(old_str, front, front.start, front.end);
	if (old_str)
		free(old_str);
	if (front.end == -1)
	{
		front = front.next;
		free(prev);
	}
	else
	{
		front.start = front.end + 1;
		front.end = -1;
	}
}
char	*get_next_line(int fd)
{
	static t_box	*front;
	char	*str;
	t_box	*curr_end;

	if (fd < 0)
		return (NULL);
	if (!front)
	{
		front = malloc(sizeof(t_box));
		if (!front)
			return (NULL);
		front.start = 0;
		read_nl(front, fd);
	}
	curr_end = front;
	while (curr_end.end == -1)
		read_nl(curr_end, fd);
	while (front != curr_end)
		ft_join(str, front);
	ft_join(str, front);
	return (str);
}


