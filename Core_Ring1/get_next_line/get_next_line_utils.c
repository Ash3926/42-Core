/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:28:49 by asolomon          #+#    #+#             */
/*   Updated: 2025/06/17 19:42:43 by asolomon         ###   ########.fr       */
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
		return (ft_strdup(s1));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2, ssize_t to_join)
{
	char	*final;
	int		i;
	int		j;

	if (!s1 || !s2 || !to_join)
		return (null_handler(s1, s2, to_join));
	i = ft_strlen(s1) + to_join;
	final = (char *)malloc(i + 1);
	if (final == NULL)
		return (final);
	i = 0;
	while (s1[i])
	{
		final[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && j < to_join)
		final[i++] = s2[j++];
	final[i] = 0;
	return (final);
}

void	ft_bzero(void *str, size_t n)
{
	size_t			erased;
	unsigned char	*holder;

	if (str == NULL)
		return ;
	erased = 0;
	holder = (unsigned char *)str;
	while (erased < n)
	{
		holder[erased] = 0;
		erased++;
	}
}

char	*ft_cpy(char *buffer, ssize_t start, ssize_t end)
{
	char	*final;
	int		i;

	final = (char *)malloc(end - start + 2);
	if (!final)
		return (final);
	i = 0;
	while (start <= end)
	{
		final[i] = buffer[start];
		i++;
		start++;
	}
	final[i] = 0;
	return (final);
}
