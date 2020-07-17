/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_others.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <gshamika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:19:00 by gshamika          #+#    #+#             */
/*   Updated: 2019/10/28 11:52:06 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

void			tm_print_exit(t_tm_list **tm_list, const char *message)
{
	if (tm_list)
		tm_lst_free(tm_list);
	ft_putstr(message);
	exit(0);
}

int				sqroot_rndup(int n)
{
	int			i;

	i = 0;
	while (i * i < n)
		i++;
	return (i);
}

int				tm_get_min_size(t_tm_list *tm_list)
{
	int			figures;
	int			squares;

	if (!tm_list)
		return (0);
	figures = 0;
	squares = 0;
	while (tm_list)
	{
		figures++;
		if (tm_list->figure == 51)
			squares++;
		tm_list = tm_list->next;
	}
	if (figures == squares && (squares == 5 || (squares >= 10 && squares <=
			12) || (squares >= 17 && squares <= 20) || squares == 26))
		return (sqroot_rndup(figures * 4) + 1);
	return (sqroot_rndup(figures * 4));
}

int				tm_place_all_figs(t_tm_list *tm_list,
										unsigned short **square, int size)
{
	t_coords	coords;

	coords.y = 0;
	while (coords.y < size)
	{
		coords.x = 0;
		while (coords.x < size)
		{
			if (tm_check_fig(tm_list, *square, size, coords))
			{
				tm_place_fig(tm_list, square, coords);
				if (tm_list->next)
				{
					if (tm_place_all_figs(tm_list->next, square, size))
						return (1);
					tm_remove_fig(tm_list, square, coords);
				}
				else
					return (1);
			}
			coords.x++;
		}
		coords.y++;
	}
	return (0);
}
