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
		while (*str == c)
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

static char	*split_helper(char const *s, int i, int nexsize)
{
	int		j;
	char	*curr_str;

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

static void	*free_words(char **arr, int i)
{
	int	curr;

	curr = 0;
	while (curr < i)
		free(arr[curr++]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	arr = malloc((checksize(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (arr);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			arr[j] = split_helper(s, i, nextsize(s, c, i));
			i += nextsize(s, c, i);
			if (!arr[j++])
				return (free_arr(arr, j - 1));
		}
		else
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
