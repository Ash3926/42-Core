/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:33:44 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/05 18:49:42 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *str, size_t n)
{
	size_t			curr;
	unsigned char	*hold;
	unsigned char	storage[10000];
	unsigned char	*source;

	if (dest == NULL || (void *)str == NULL)
		return (NULL);
	hold = (unsigned char *)dest;
	source = (unsigned char *)str;
	curr = 0;
	while (curr < n)
	{
		storage[curr] = source[curr];
		curr++;
	}
	curr = 0;
	while (curr < n)
	{
		hold[curr] = storage[curr];
		curr++;
	}
	return (dest);
}
/* TEST CASE
#include <stdio.h>
int	main()
{
	void	*final;
	char	str[] = "H3llo World!";

	final = malloc(50);
	ft_memmove(final, (const void *)str, 7);
	printf("%s", (char *)final);
}
*/
