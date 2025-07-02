/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:57:05 by asolomon          #+#    #+#             */
/*   Updated: 2025/07/02 22:14:09 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

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
	printf("curr_end : %zi", end);
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
	printf("Curr_end : %zi", curr_end->end);
	printf("Line read\n");
	return (curr_end);
}

char	*ft_join(char *str, t_box *front)
{
	t_box	*prev;
	char	*old_str;

	old_str = str;
	prev = front;
	printf("Calling Strjoin, start %zi, end %zi\n", front->start, front->end);
	str = ft_strjoin(old_str, front->space, front->start, front->end);
	printf("String joined and returned\n");
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
	printf("String Joined, exit\n");
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
	{
		printf("Started\n");
		front = malloc(sizeof(t_box));
		if (!front)
			return (NULL);
		front->start = 0;
		ft_bzero(front->space, BUFFER_SIZE);
		printf("Reading first line\n");
		front = read_nl(front, fd);
		printf("Curr_end : %s", front->space);
	}
	curr_end = front;
	while (curr_end->end == -1)
	{
		printf("Next read\n");
		read_nl(curr_end, fd);
	}
	while (front != curr_end)
	{
		printf("Front info : %s", front->space);
		str = ft_join(str, front);
	}
	printf("Joining\n");
	str = ft_join(str, front);
	printf("Joined and returning\n");
	printf("%s",str);
	return (str);
}
