/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:12:16 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/09 18:19:51 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	checklen(char const *str, int i)
{
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		i;

	i = checklen(s1, 0);
	i = checklen(s2, i);
	final = (char *)malloc(i);
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
	return (final);
}
