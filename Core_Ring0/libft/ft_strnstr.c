/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:28:58 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/22 20:38:46 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *main, const char *sub, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	subsize;

	i = 0;
	subsize = 0;
	if ((main == sub && len >= ft_strlen(main)) || *sub == 0)
		return ((char *)main);
	while (sub[subsize])
		subsize++;
	while (main[i] && (i < len))
	{
		j = 0;
		while ((main[i + j] == sub[j]) && (i + j) < len)
			j++;
		if (j == subsize)
			return ((char *)&main[i]);
		i++;
	}
	return (NULL);
}
