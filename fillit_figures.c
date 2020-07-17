/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_figures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <gshamika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:46:17 by gshamika          #+#    #+#             */
/*   Updated: 2019/10/26 16:24:20 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

int			tm_check_fig(t_tm_list *tm_list, unsigned short *square,
					int size, t_coords coords)
{
	int		bit;

	bit = 0;
	while (bit < 16)
	{
		if (bit_get(bit, &(tm_list->figure)))
		{
			if (coords.x + bit % 4 >= size || (coords.y + bit / 4 >= size))
				return (0);
			if (bit_get(coords.x + bit % 4, &(square[coords.y + bit / 4])))
				return (0);
		}
		bit++;
	}
	return (1);
}

void		tm_place_fig(t_tm_list *tm_list, unsigned short **square,
					t_coords coords)
{
	int		bit;

	bit = 0;
	while (bit < 16)
	{
		if (bit_get(bit, &(tm_list->figure)))
			bit_set(coords.x + bit % 4, &((*square)[coords.y + bit / 4]));
		bit++;
	}
	tm_list->x = coords.x;
	tm_list->y = coords.y;
}

void		tm_remove_fig(t_tm_list *tm_list, unsigned short **square,
					t_coords coords)
{
	int		bit;

	bit = 0;
	while (bit < 16)
	{
		if (bit_get(bit, &(tm_list->figure)))
			bit_reset(coords.x + bit % 4, &((*square)[coords.y + bit / 4]));
		bit++;
	}
	tm_list->x = 0;
	tm_list->y = 0;
}

void		tm_offset_figure(unsigned short *figure)
{
	while (!(bit_get(0, figure)) && !(bit_get(1, figure)) &&
			!(bit_get(2, figure)) && !(bit_get(3, figure)))
		*figure = *figure >> 4;
	while (!(bit_get(0, figure)) && !(bit_get(4, figure)) &&
			!(bit_get(8, figure)) && !(bit_get(12, figure)))
		*figure = *figure >> 1;
}

int			tm_validate_figure(char *buf)
{
	int		connects;
	int		i;
	int		blocks;

	connects = 0;
	i = 0;
	blocks = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
		{
			blocks++;
			if (i > 4 && buf[i - 5] == '#')
				connects++;
			if (i < 15 && buf[i + 5] == '#')
				connects++;
			if (i % 5 != 0 && buf[i - 1] == '#')
				connects++;
			if (buf[i] != '\n' && buf[i + 1] == '#')
				connects++;
		}
		i++;
	}
	return (connects < 6 || blocks > 4) ? 0 : 1;
}
