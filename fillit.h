/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <gshamika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:01:17 by gshamika          #+#    #+#             */
/*   Updated: 2019/10/28 12:16:04 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct			s_tm_list
{
	char				letter;
	int					x;
	int					y;
	unsigned short		figure;
	struct s_tm_list	*next;
}						t_tm_list;

typedef struct			s_coords
{
	int					x;
	int					y;
}						t_coords;

char					**tm_squarealloc(int size);
char					**tm_set(int size);
char					**tm_swap_p_sq(char **p_square, t_tm_list *tm_list);
void					tm_free(char **p_sq, int size);
int						tm_print_square(t_tm_list *tm_list, int size);

void					tm_print_exit(t_tm_list **tm_list, const char *message);
int						sqroot_rndup(int n);
int						tm_get_min_size(t_tm_list *tm_list);
int						tm_place_all_figs(t_tm_list *tm_list,
								unsigned short **square, int size);

void					tm_lst_free(t_tm_list **tm_list);
t_tm_list				*tm_lst_new(char letter, char *buf);
void					tm_lst_add(t_tm_list **tm_list, char *buf);
int						tm_get_list(int fd, t_tm_list **tm_list);

int						tm_check_fig(t_tm_list *tm_list, unsigned short *square,
								int size, t_coords coords);
void					tm_place_fig(t_tm_list *tm_list,
								unsigned short **square, t_coords coords);
void					tm_remove_fig(t_tm_list *tm_list,
								unsigned short **square, t_coords coords);
void					tm_offset_figure(unsigned short *figure);
int						tm_validate_figure(char *buf);

#endif
