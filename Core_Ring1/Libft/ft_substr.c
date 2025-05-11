/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:58:59 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/09 18:11:59 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	sub = (char *)malloc(len);
	if (sub == NULL)
		return (sub);
	while ((size_t)i < len)
	{
		sub[i] = (char)s[i + start];
		i++;
	}
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
