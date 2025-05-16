/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:12:16 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/14 12:20:25 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		i;

	i = ft_strlen(s1);
	i = i + ft_strlen(s2);
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
