/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:28:49 by asolomon          #+#    #+#             */
/*   Updated: 2025/07/03 22:12:45 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*null_handler(char const *s1, char const *s2, ssize_t to_join)
{
	char	*final;
	int		i;

	if (!s1 && s2 && to_join)
	{
		i = 0;
		final = malloc(to_join + 1);
		while (i < to_join)
		{
			final[i] = s2[i];
			i++;
		}
		final[i] = 0;
		return (final);
	}
	if ((to_join == 0) || (!s2 && s1))
		return ((char *)s1);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2, ssize_t to_join)
{
	char	*final;
	int		i;
	int		j;

	if (!s1 || !s2 || !to_join)
		return (null_handler(s1, s2, to_join));
	i = 0;
	while (s1[i])
		i++;
	i = i + to_join;
	final = (char *)malloc(i + 1);
	if (final == NULL)
		return (final);
	i = 0;
	while (s1[i++])
		final[i - 1] = s1[i - 1];
	j = 0;
	i -= 1;
	while (s2[j] && j < to_join)
		final[i++] = s2[j++];
	final[i] = 0;
	free((void *)s1);
	return (final);
}

char	*ft_cpy(char *buffer, ssize_t start, ssize_t end, ssize_t bytes)
{
	char		*final;
	ssize_t		i;
	ssize_t		malloc_size;

	if (end == -1)
		malloc_size = bytes - start;
	else
		malloc_size = end - start;
	final = (char *)malloc(malloc_size + 1);
	if (!final)
		return (final);
	i = 0;
	while (i < malloc_size)
	{
		final[i] = buffer[start + 1];
		i++;
		start++;
	}
	final[i] = 0;
	return (final);
}

char	*ft_bzero(void *str, size_t n)
{
	size_t			erased;
	char			*holder;

	if (str == NULL)
		return (NULL);
	erased = 0;
	holder = (char *)str;
	while (erased < n)
	{
		holder[erased] = 0;
		erased++;
	}
	return (holder);
}
