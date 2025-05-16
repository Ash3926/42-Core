/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:46:35 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/14 13:06:51 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	checksize(char const *str, char c)
{
	int	len;

	len = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (!(*str))
			return (len);
		len++;
		while (*str != c && *str)
			str++;
	}
	return (len);
}

static int	nextsize(char const *str, char c, int i)
{
	int	size;

	size = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		size++;
	}
	return (size);
}

static char	*split_helper(char const *s, char *curr_str, int i, int nexsize)
{
	int	j;

	j = 0;
	curr_str = (char *)malloc(nexsize + 1);
	if (curr_str == NULL)
		return (curr_str);
	while (j < nexsize)
	{
		curr_str[j] = s[i + j];
		j++;
	}
	curr_str[j] = 0;
	return (curr_str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*curr_str;
	int		i;
	int		j;

	arr = malloc((checksize(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (arr);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (nextsize(s, c, i))
		{
			curr_str = split_helper(s, curr_str, i, nextsize(s, c, i));
			i += nextsize(s, c, i);
			arr[j++] = curr_str;
		}
		i++;
	}
	arr[j] = NULL;
	return (arr);
}
/* TEST CASE
#include <stdio.h>
int	main()
{
	const char	s[] = "H3y th3r33!!\0";
	char	**arr;
	arr = ft_split(s, '3');
	printf("%s\n", arr[0]);
	printf("%s", arr[1]);
}
*/
