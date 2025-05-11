/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:07:39 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/08 16:09:51 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;
	size_t		check;

	len = 0;
	if (*dst == 0 || *src == 0)
		return (len);
	while (dst[len] && len < size - 1)
	{
		len++;
	}
	check = len;
	while (src[len - check] && (len < (size - 1)))
	{
		dst[len] = src[len - check];
		len++;
	}
	if (len < size)
		dst[len] = 0;
	return (len);
}
