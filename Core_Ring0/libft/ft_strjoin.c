/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:12:16 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/25 19:27:00 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*null_handler(char const *s1, char const *s2)
{
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		i;

	if (!s1 || !s2)
		return (null_handler(s1, s2));
	i = ft_strlen(s1) + ft_strlen(s2);
	final = (char *)malloc(i + 1);
	if (final == NULL)
		return (final);
	i = 0;
	while (s1[i])
	{
		final[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		final[i] = *s2;
		i++;
		s2++;
	}
	final[i] = 0;
	return (final);
}
