/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:59:04 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/11 18:48:03 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return ((size_t)ft_strlen(src));
	while ((i < size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return ((size_t)ft_strlen((char *)src));
}
/* TEST CASE
#include <stdio.h>
int	main()
{
	char *dst;

	dst = malloc(20);
	printf("%d", (int)ft_strlcpy(dst, "lorem ipsum", 0));
	printf("%s", dst);
}
*/
