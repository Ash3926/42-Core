/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigneditoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:19:42 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/28 14:55:53 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	findsize(unsigned int c)
{
	int	size;

	size = 0;
	if (c == 0)
		return (1);
	while (c != 0)
	{
		size++;
		c /= 10;
	}
	return (size);
}

void	str_revrse(char *str)
{
	size_t	i;
	size_t	end;
	char	hold;

	i = 0;
	end = ft_strlen((const char *)str) - 1;
	while (i < end)
	{
		hold = str[i];
		str[i++] = str[end];
		str[end--] = hold;
	}
}

char	*ft_unsigneditoa(unsigned int c)
{
	char	*str;
	int		size;
	int		i;

	size = findsize(c);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i++] = (c % 10) + '0';
		c /= 10;
	}
	str[i] = 0;
	str_revrse(str);
	return (str);
}

/*TEST
#include <stdio.h>
int	main()
{
	printf("%s\n", ft_unsigneditoa(-1));
	printf("%u\n", -1);
}
*/
