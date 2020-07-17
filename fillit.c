/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <gshamika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:10:36 by gshamika          #+#    #+#             */
/*   Updated: 2019/10/28 17:51:47 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

int					main(int argc, char **argv)
{
	int				fd;
	int				size;
	t_tm_list		*tm_list;
	unsigned short	square[16];
	unsigned short	*p_square;

	if (argc != 2)
		tm_print_exit(NULL, "usage: fillit source_file\n");
	fd = open(argv[1], O_RDONLY);
	tm_list = NULL;
	if (!(tm_get_list(fd, &tm_list)))
		tm_print_exit(&tm_list, "error\n");
	close(fd);
	size = tm_get_min_size(tm_list);
	p_square = square;
	ft_bzero(p_square, 32);
	while (!(tm_place_all_figs(tm_list, &p_square, size)))
	{
		ft_bzero(p_square, 32);
		size++;
	}
	if (!(tm_print_square(tm_list, size)))
		tm_print_exit(&tm_list, "error\n");
	tm_lst_free(&tm_list);
	return (0);
}
