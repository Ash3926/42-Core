/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:19:25 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/14 18:28:44 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*next_pointer;

	len = 0;
	next_pointer = lst;
	while ((void *)next_pointer != NULL)
	{
		len++;
		next_pointer = next_pointer->next;
	}
	return (len);
}
