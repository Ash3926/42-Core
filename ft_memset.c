/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:03:16 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/05 17:33:02 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *space, int c, size_t n)
{
	size_t			i;
	unsigned char	*holder;

	if (*space == NULL)
		return ;
	holder = (unsigned char *)space;
	i = 0;
	while (i < n)
	{
		holder[i] = c;
		i++;
	}
	return (space);
}
/* TEST CASE
#include <stdio.h>
int	main(void)
{
	void	*hold;

	hold = malloc(50);
	ft_memset(hold, 122, 2);
	printf("%s", (unsigned char *)hold);
	return (0);
}
*/
