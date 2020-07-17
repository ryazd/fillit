/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <gshamika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:19:02 by gshamika          #+#    #+#             */
/*   Updated: 2019/10/26 15:19:02 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	bit_set(int bit, unsigned short *figure)
{
	bit = 1 << bit;
	*figure = *figure | bit;
}

void	bit_reset(int bit, unsigned short *figure)
{
	bit = 1 << bit;
	bit ^= 0xffff;
	*figure = *figure & bit;
}

int		bit_get(int bit, unsigned short *figure)
{
	bit = 1 << bit;
	return (bit & *figure);
}
