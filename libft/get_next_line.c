/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <gshamika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:31:59 by gshamika          #+#    #+#             */
/*   Updated: 2019/10/25 18:24:46 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*lst_get_content(const int fd, t_list **fd_list)
{
	t_list			*new_list;
	t_list			*temp_list;

	if (!(*fd_list))
	{
		if (!(new_list = ft_lstnew("", fd)))
			return (NULL);
		ft_lstadd(fd_list, new_list);
		return (*fd_list);
	}
	if ((int)((*fd_list)->content_size) == fd)
		return (*fd_list);
	temp_list = *fd_list;
	while (temp_list->next)
	{
		if ((int)(temp_list->next->content_size) == fd)
			return (temp_list->next);
		temp_list = temp_list->next;
	}
	if (!(new_list = ft_lstnew("", fd)))
		return (NULL);
	ft_lstadd(&((*fd_list)->next), new_list);
	return (new_list);
}

static void			lst_del_fd(const int fd, t_list **fd_list)
{
	t_list			*start;
	t_list			*temp;

	if ((int)((*fd_list)->content_size) == fd)
	{
		free((*fd_list)->content);
		(*fd_list)->content = NULL;
		temp = (*fd_list)->next;
		(*fd_list)->next = NULL;
		free(*fd_list);
		*fd_list = temp;
	}
	else
	{
		start = *fd_list;
		while ((int)((*fd_list)->next->content_size) != fd)
			*fd_list = (*fd_list)->next;
		free((*fd_list)->next->content);
		(*fd_list)->next->content = NULL;
		temp = (*fd_list)->next->next;
		(*fd_list)->next->next = NULL;
		free((*fd_list)->next);
		(*fd_list)->next = temp;
		*fd_list = start;
	}
}

static int			addline(t_list *node, char **line)
{
	int				res;
	char			*temp;

	res = 0;
	while (((char *)(node->content))[res] != '\0')
	{
		if (((char *)(node->content))[res] == '\n')
		{
			((char *)(node->content))[res] = '\0';
			if (!(*line = ft_strjoin(*line, node->content)))
				return (-1);
			temp = node->content;
			node->content = ft_strdup(node->content + res + 1);
			free(temp);
			if (!(node->content))
				return (-1);
			return (1);
		}
		res++;
	}
	if (!(*line = ft_strjoin(*line, node->content)))
		return (-1);
	((char *)(node->content))[0] = '\0';
	return (1);
}

static int			readlines(t_list *node, const int fd)
{
	int				res;
	char			buf[51];
	char			*temp;

	if (read(fd, buf, 0) == -1)
		return (-1);
	if (!(ft_strchr(node->content, '\n')))
	{
		while ((res = read(fd, buf, 50)))
		{
			buf[res] = '\0';
			temp = node->content;
			node->content = ft_strjoin(node->content, buf);
			free(temp);
			if (!(node->content))
				return (-1);
			if (ft_strchr(buf, '\n'))
				return (res);
		}
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int				res;
	static t_list	*fd_list = NULL;
	t_list			*node;

	if (fd < 0 || fd > FD_SETSIZE || !line)
		return (-1);
	*line = NULL;
	if (!(node = lst_get_content(fd, &fd_list)))
		return (-1);
	res = readlines(node, fd);
	if (res == -1)
		return (-1);
	if (res == 0 && ((char *)(node->content))[0] == '\0')
	{
		lst_del_fd(fd, &fd_list);
		return (0);
	}
	res = addline(node, line);
	return (res);
}
