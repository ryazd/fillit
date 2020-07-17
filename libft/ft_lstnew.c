/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:54:55 by gshamika          #+#    #+#             */
/*   Updated: 2019/09/18 21:11:00 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*list_content;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list_content = (void *)malloc(content_size)))
		{
			free(list);
			return (NULL);
		}
		list_content = ft_memcpy(list_content, content, content_size);
		list->content = list_content;
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
