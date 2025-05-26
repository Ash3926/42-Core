/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:28:58 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/25 19:05:12 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *main, const char *sub, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	subsize;

	i = 0;
	if (!main || !sub)
		return (NULL);
	if ((main == sub && len >= ft_strlen(main)) || *sub == 0)
		return ((char *)main);
	subsize = ft_strlen(sub);
	if (subsize > len)
		return (NULL);
	while (main[i] && (i < len))
	{
		j = 0;
		while ((i + j) < len && (main[i + j] == sub[j]))
			j++;
		if (j == subsize)
			return ((char *)&main[i]);
		i++;
	}
	return (NULL);
}
