/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:36:23 by asolomon          #+#    #+#             */
/*   Updated: 2025/07/02 22:55:25 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *c)
{
	size_t	len;
	
	len = 0;
	while (c[len])
                len++;
	return (len);
}

char	*start_handler(char *s2, ssize_t start, ssize_t end)
{
	char	*final;
	ssize_t	i;

	i = 0;
	if (end == -1)
		end = BUFFER_SIZE;
	final = malloc(end - start + 1);
	if (final == NULL)
		return (final);
	while (start < end + 1)
	{
		final[i++] = s2[start++];
	}
	final[i] = 0;
	return (final);
}

char	*ft_strjoin(char *s1, char *s2, ssize_t start, ssize_t end)
{
	char	*final;
	ssize_t		i;
	ssize_t		j;

	if (!s1)
		return (start_handler(s2, start, end));
	if (end == -1)
		end = BUFFER_SIZE;
	i = ft_strlen(s1) + (end - start);
	final = malloc(i + 1);
	if (final == NULL)
		return (final);
	j = 0;
	while (j < i && s1[j])
	{
		final[j] = s1[j];
		j++;
	}
	while (j < i && start < end)
		final[j++] = s2[start++];
	final[j] = 0;
	return (final);
}

void	ft_bzero(char *str, ssize_t n)
{
	ssize_t	erased;

	if (str == NULL)
		return ;
	erased = 0;
	while (erased < n)
	{
		str[erased] = 0;
		erased++;
	}
}
