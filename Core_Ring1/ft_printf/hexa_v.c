/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:06:07 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/28 16:40:28 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	strsize(uintptr_t c)
{
	int	size;

	size = 0;
	while (c != 0)
	{
		size++;
		c /= 16;
	}
	return (size);
}

static void	str_revrse(char *str)
{
	int		start;
	int		end;
	char	hold;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		hold = str[start];
		str[start++] = str[end];
		str[end--] = hold;
	}
}

char	*hexa_v(void *addr)
{
	char		*hexcode;
	char		*str;
	int			i;
	uintptr_t	intaddr;

	i = 0;
	intaddr = (uintptr_t)addr;
	hexcode = "0123456789abcdef";
	str = malloc(strsize(intaddr) + 3);
	if (!str)
		return (NULL);
	while (intaddr != 0)
	{
		str[i++] = hexcode[intaddr % 16];
		intaddr /= 16;
	}
	str[i++] = 'x';
	str[i++] = '0';
	str[i] = 0;
	str_revrse(str);
	return (str);
}

/* TEST
#include <stdio.h>
int main()
{
	void	*a = "hello";

	printf("%s , %p", hexa_v(a), a);
}
*/
