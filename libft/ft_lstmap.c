/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:39:21 by gshamika          #+#    #+#             */
/*   Updated: 2019/09/18 21:09:55 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		freelst(t_list *lst)
{
	if (lst)
	{
		if (lst->next)
		{
			lst = lst->next;
			freelst(lst);
		}
		lst->content = NULL;
		lst->content_size = 0;
		lst->next = NULL;
		free(lst);
		lst = NULL;
	}
}

static t_list	*add_new_node(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_node;

	new_node = NULL;
	if (!(new_node = (t_list *)malloc(sizeof(t_list))))
	{
		freelst(lst);
		return (NULL);
	}
	*new_node = *((*f)(lst));
	return (new_node);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;

	new_lst = NULL;
	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!lst || !f || !new_lst)
		return (NULL);
	*new_lst = *((*f)(lst));
	lst = lst->next;
	while (lst)
	{
		ft_lstaddend(&new_lst, add_new_node(lst, f));
		lst = lst->next;
	}
	return (new_lst);
}
