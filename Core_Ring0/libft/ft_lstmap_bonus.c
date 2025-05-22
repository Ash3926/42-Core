/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:10:37 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/22 20:48:34 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst_top;
	t_list	*currnew_lst_node;
	t_list	*next_node;

	new_lst_top = ft_lstnew(f(lst->content));
	if (new_lst_top == NULL)
		return (NULL);
	currnew_lst_node = new_lst_top;
	lst = lst->next;
	while (lst)
	{
		next_node = ft_lstnew(f(lst->content));
		if (!(next_node))
		{
			ft_lstclear(&new_lst_top, del);
			return (NULL);
		}
		currnew_lst_node->next = next_node;
		currnew_lst_node = currnew_lst_node->next;
		lst = lst->next;
	}
	if (new_lst_top)
		currnew_lst_node->next = NULL;
	return (new_lst_top);
}
