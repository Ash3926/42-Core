/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:28:49 by asolomon          #+#    #+#             */
/*   Updated: 2025/06/17 20:55:19 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*return_str;

	i = 0;
	while (str[i])
		i++;
	return_str = malloc(i + 1);
	if (return_str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		return_str[i] = str[i];
		i++;
	}
	return_str[i] = '\0';
	return (return_str);
}

static char	*null_handler(char const *s1, char const *s2, ssize_t to_join)
{
	char	*final;
	int		i;

	if (!s1 && s2 && to_join)
	{
		i = 0;
		final = malloc(to_join + 1);
		while (i < to_join + 1)
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

char	*ft_cpy(char *buffer, ssize_t start, ssize_t size)
{
	char	*final;
	int		i;

	final = (char *)malloc(size + 1);
	if (!final)
		return (final);
	i = 0;
	while (i <= size)
	{
		final[i] = buffer[start + 1];
		i++;
		start++;
	}
	final[i] = 0;
	return (final);
}
