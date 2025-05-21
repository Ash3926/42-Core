/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:55:30 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/05 17:33:31 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t			erased;
	unsigned char	*holder;

	if (str == NULL)
		return ;
	erased = 0;
	holder = (unsigned char *)str;
	while (erased < n)
	{
		holder[erased] = 0;
		erased++;
	}
}
