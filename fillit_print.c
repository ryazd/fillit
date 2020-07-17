/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <gshamika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:42:47 by gshamika          #+#    #+#             */
/*   Updated: 2019/10/28 14:02:17 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

void		tm_free(char **p_sq, int size)
{
	while (size > 0)
	{
		free(p_sq[size - 1]);
		size--;
	}
	free(p_sq);
}

char		**tm_squarealloc(int size)
{
	int		i;
	char	**sq;

	i = 0;
	if (!(sq = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (i < size)
	{
		if (!(sq[i] = (char *)malloc(sizeof(char) * (size + 1))))
		{
			tm_free(sq, i);
			return (NULL);
		}
		i++;
	}
	return (sq);
}

char		**tm_set(int size)
{
	int		x;
	int		y;
	char	**p_square;

	if ((p_square = tm_squarealloc(size)) == NULL)
		return (NULL);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			p_square[y][x] = '.';
			x++;
		}
		p_square[y][x] = '\0';
		y++;
	}
	return (p_square);
}

char		**tm_swap_p_sq(char **p_square, t_tm_list *tm_list)
{
	int		bit;
	int		x;
	int		y;

	while (tm_list)
	{
		bit = 0;
		while (bit < 16)
		{
			if (bit_get(bit, &(tm_list->figure)))
			{
				x = tm_list->x + bit % 4;
				y = tm_list->y + bit / 4;
				p_square[y][x] = tm_list->letter;
			}
			bit++;
		}
		tm_list = tm_list->next;
	}
	return (p_square);
}

int			tm_print_square(t_tm_list *tm_list, int size)
{
	char	**p_square;
	int		y;

	if ((p_square = tm_set(size)) == NULL)
		return (0);
	p_square = tm_swap_p_sq(p_square, tm_list);
	y = 0;
	while (y < size)
	{
		ft_putstr(p_square[y]);
		write(1, "\n", 1);
		y++;
	}
	tm_free(p_square, size);
	return (1);
}
