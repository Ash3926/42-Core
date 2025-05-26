/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:58:59 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/25 18:56:17 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*blank_handler(void)
{
	char	*str;

	str = (char *)malloc(1);
	str[0] = 0;
	return (str);
}

static int	size_set(char const *s, unsigned int start, size_t len)
{
	unsigned int	n;
	unsigned int	size;

	n = (unsigned int)len;
	size = 0;
	while (size < n && s[start])
	{
		start++;
		size++;
	}
	return ((int)size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	int				size;

	i = 0;
	if (!s || len <= 0 || ((size_t)start > ft_strlen(s)))
		return (blank_handler());
	size = size_set(s, start, len);
	sub = (char *)malloc(size + 1);
	if (sub == NULL)
		return (sub);
	while (((size_t)i < len) && s[i + start])
	{
		sub[i] = (char)s[i + start];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
/* TEST CASE
#include <stdio.h>
int	main()
{
	char const string[] = "Hello World!";
	unsigned int	num = 5;
	printf("%s", ft_substr(string, num, 5));
}
*/
