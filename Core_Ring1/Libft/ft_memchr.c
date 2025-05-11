/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:02:26 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/08 17:15:04 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*space;
	size_t			i;
	unsigned char	cee;

	cee = (unsigned char)c;
	if ((void *)s == NULL)
		return (NULL);
	space = (unsigned char *)s;
	i = 0;
	while (space[i] && (i < n))
	{
		if (space[i] == c)
			return (&space[i]);
		i++;
	}
	return (NULL);
}
