/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <gshamika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:40:13 by gshamika          #+#    #+#             */
/*   Updated: 2019/10/28 12:18:42 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

void				tm_lst_free(t_tm_list **tm_list)
{
	t_tm_list		*temp;

	while (*tm_list)
	{
		temp = *tm_list;
		*tm_list = (*tm_list)->next;
		temp->next = NULL;
		free(temp);
	}
	*tm_list = NULL;
}

t_tm_list			*tm_lst_new(char letter, char *buf)
{
	t_tm_list		*new_list;
	unsigned short	figure;
	int				i;

	if (!(new_list = (t_tm_list *)malloc(sizeof(t_tm_list))))
		tm_print_exit(NULL, "error\n");
	new_list->letter = letter;
	new_list->x = 0;
	new_list->y = 0;
	new_list->next = NULL;
	figure = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
			bit_set(i - i / 5, &figure);
		i++;
	}
	tm_offset_figure(&figure);
	new_list->figure = figure;
	return (new_list);
}

void				tm_lst_add(t_tm_list **tm_list, char *buf)
{
	t_tm_list		*temp_list;

	if (!(*tm_list))
		*tm_list = tm_lst_new('A', buf);
	else
	{
		temp_list = *tm_list;
		while (temp_list->next)
			temp_list = temp_list->next;
		if (temp_list->letter == 'Z')
			tm_print_exit(tm_list, "error\n");
		temp_list->next =
				tm_lst_new((char)(((int)temp_list->letter) + 1), buf);
	}
}

int					tm_get_list(const int fd, t_tm_list **tm_list)
{
	int				res;
	int				res_prev;
	char			buf[22];
	int				i;

	res_prev = 0;
	while ((res = read(fd, buf, 21)))
	{
		res_prev = res;
		buf[res] = '\0';
		i = 0;
		while (buf[i] != '\0')
		{
			if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
				return (0);
			if (buf[i] == '\n' && i % 5 != 4 && i != 20)
				return (0);
			i++;
		}
		if (res < 20 || !(tm_validate_figure(buf)))
			return (0);
		tm_lst_add(tm_list, buf);
	}
	return (res_prev != 20 ? 0 : 1);
}
