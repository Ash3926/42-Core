/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:24:51 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/09 18:46:16 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	check_in(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	checklen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*trimmed;

	start = 0;
	end = checklen(s1) - 1;
	while (check_in(s1[start], set) && start < end)
		start++;
	while (check_in(s1[end], set) && end > start)
		end--;
	trimmed = (char *)malloc(end - start + 1);
	if (trimmed == NULL || start == end)
		return (trimmed);
	i = 0;
	while (start <= end)
	{
		trimmed[i] = (char)s1[start];
		start++;
		i++;
	}
	trimmed[i] = 0;
	return (trimmed);
}
/* TEST CASE
#include <stdio.h>
int main()
{
    printf("%s", ft_strtrim("  Hello World!   ", "! "));
}
*/
