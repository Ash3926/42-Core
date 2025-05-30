/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:10:37 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/25 19:28:49 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst_top;
	t_list	*currnew_lst_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst_top = ft_lstnew(f(lst->content));
	if (new_lst_top == NULL)
		return (NULL);
	currnew_lst_node = new_lst_top;
	lst = lst->next;
	while (lst)
	{
		currnew_lst_node->next = ft_lstnew(f(lst->content));
		if (!(currnew_lst_node->next))
		{
			ft_lstclear(&new_lst_top, del);
			return (NULL);
		}
		currnew_lst_node = currnew_lst_node->next;
		lst = lst->next;
	}
	return (new_lst_top);
}
