/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:33:45 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/28 14:20:07 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	findsize(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_itoa_helper(char *str, int n, int i)
{
	if (n >= 10)
	{
		str[i] = (n % 10) + '0';
		i++;
		n /= 10;
		ft_itoa_helper(str, n, i);
	}
	if (n < 10)
	{
		str[i] = (n + '0');
		str[i + 1] = 0;
	}
	return (str);
}

static char	*special_case(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = 0;
	return (str);
}

static char	*revrse(char *str, int start)
{
	int		end;
	char	temp;

	end = 0;
	while (str[end + 1])
		end++;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = (char *)malloc(findsize(n) + 1);
	if (str == NULL)
		return (str);
	if (n == -2147483648)
		str = special_case(str);
	else if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		str = ft_itoa_helper(str, n, 1);
		str = revrse(str, 1);
	}
	else
	{
		str = ft_itoa_helper(str, n, 0);
		str = revrse(str, 0);
	}
	return (str);
}
/* TEST CASE
#include <stdio.h>
int main()
{
  printf("%s\n", ft_itoa(10));
  printf("%s\n", ft_itoa(0));
  printf("%s\n", ft_itoa(-2147483648));
}
*/
