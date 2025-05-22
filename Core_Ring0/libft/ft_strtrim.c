/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:24:51 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/14 12:48:11 by asolomon         ###   ########.fr       */
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

static char	*blank_handler(void)
{
	char	*trimmed;

	trimmed = (char *)malloc(1);
	if (trimmed == NULL)
		return (trimmed);
	trimmed[0] = 0;
	return (trimmed);
}

static int	*num_setter(char const *s1, char const *set, int indexes[2])
{
	int	index1;
	int	index2;

	index1 = 0;
	index2 = ft_strlen(s1) - 1;
	while (check_in(s1[index1], set) && (index1 <= index2))
		index1++;
	while (check_in(s1[index2], set) && (index1 <= index2))
		index2--;
	indexes[0] = index1;
	indexes[1] = index2;
	return (indexes);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	int		indexes[2];
	char	*trimmed;

	start = num_setter(s1, set, indexes)[0];
	end = num_setter(s1, set, indexes)[1];
	if (start > end)
		return (blank_handler());
	trimmed = (char *)malloc(end - start + 2);
	if (trimmed == NULL)
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
