/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:10:37 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/16 16:49:48 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_list	*ft_lstmap_helper(t_list *old_lst_node, void *(*f)(void *))
{
	t_list	*new_lst_node;

	new_lst_node = malloc(sizeof(t_list));
	if (!(new_lst_node))
		return (NULL);
	new_lst_node->content = malloc(sizeof(f(old_lst_node->content)));
	if (!(new_lst_node->content))
		return (NULL);
	new_lst_node->content = f(old_lst_node->content);
	return (new_lst_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst_top;
	t_list	*currnew_lst_node;
	t_list	*old_lst_node;

	new_lst_top = ft_lstmap_helper(lst, f);
	if (!(new_lst_top))
		return (NULL);
	currnew_lst_node = new_lst_top;
	old_lst_node = lst->next;
	while (old_lst_node)
	{
		if (!(ft_lstmap_helper(old_lst_node, f)))
		{
			ft_lstclear(&new_lst_top, del);
			return (NULL);
		}
		currnew_lst_node->next = ft_lstmap_helper(old_lst_node, f);
		currnew_lst_node = currnew_lst_node->next;
		old_lst_node = old_lst_node->next;
	}
	currnew_lst_node->next = NULL;
	return (new_lst_top);
}
