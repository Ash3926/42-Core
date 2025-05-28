/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:06:07 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/28 18:26:49 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	strsize(unsigned int c)
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

char	*hexa_ui(unsigned int c, char flag)
{
	char	*hexcode;
	char	*str;
	int		i;

	i = 0;
	hexcode = "0123456789abcdef";
	if (c == 0)
		return (ft_strdup("0"));
	str = malloc(strsize(c) + 1);
	if (!str)
		return (NULL);
	while (c != 0)
	{
		str[i++] = hexcode[c % 16];
		c /= 16;
	}
	str[i] = 0;
	str_revrse(str);
	if (flag == 'X')
		ft_toupper(str);
	return (str);
}

/* TEST
#include <stdio.h>
int main()
{
	printf("%s , %x", hexa_ui(30002932), 30002932);
}
*/
