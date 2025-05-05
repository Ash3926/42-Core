/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:16:29 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/05 17:32:35 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *str, size_t n)
{
	size_t			curr;
	unsigned char	*hold;
	unsigned char	*source;

	if (*dest == NULL || *str == NULL)
		return ;
	hold = (unsigned char *)dest;
	source = (unsigned char *)str;
	curr = 0;
	while (curr < n)
	{
		hold[curr] = source[curr];
		curr++;
	}
	return (dest);
}
/* TEST CASE
#include <stdio.h>
int	main()
{
	void	*final;
	unsigned char	src[] = "Hello World!";

	final = malloc(50);
	ft_memcpy(final, (const void *)src, 7);
	printf("%s", (char *)final);
}
*/
