/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:34:14 by gshamika          #+#    #+#             */
/*   Updated: 2019/09/17 19:45:33 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	result[10];
	int		i;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	i = 0;
	while (n > 0)
	{
		result[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
		ft_putchar_fd(result[i], fd);
}
