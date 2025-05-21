/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:20:36 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/08 19:24:58 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*return_str;

	i = 0;
	while (str[i])
		i++;
	return_str = malloc(i + 1);
	if (return_str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		return_str[i] = str[i];
		i++;
	}
	return_str[i] = '\0';
	return (return_str);
}
