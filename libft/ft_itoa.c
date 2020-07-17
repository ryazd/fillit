/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:54:19 by gshamika          #+#    #+#             */
/*   Updated: 2019/09/18 21:10:07 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int		digits;

	digits = 0;
	if (n <= 0)
	{
		digits++;
		n = -n;
	}
	while (n > 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

char		*ft_itoa(int n)
{
	char	*result;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = count_digits(n);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	result[len--] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		result[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
