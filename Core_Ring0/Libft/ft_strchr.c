/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:18:51 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/08 16:31:39 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*holder_str;

	holder_str = (char *)str;
	while (*holder_str)
	{
		if (*holder_str == c)
			return (holder_str);
		holder_str++;
	}
	if (c == 0)
		return (holder_str);
	return (NULL);
}
/* TEST CASE
#include <stdio.h>
int	main()
{
	char	*str = "Hello World!\0";
	char	*hold;

	hold = ft_strchr((const char *)str, 'e');
	printf("%c", *hold);
}
*/
