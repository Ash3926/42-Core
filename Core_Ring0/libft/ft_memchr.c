/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:02:26 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/11 18:26:19 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*space;
	size_t			i;
	unsigned char	cee;

	cee = (unsigned char)c;
	space = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (space[i] == cee)
			return (&space[i]);
		i++;
	}
	return (NULL);
}
