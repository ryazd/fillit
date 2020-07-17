/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:14:21 by gshamika          #+#    #+#             */
/*   Updated: 2019/10/28 13:15:05 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(int sign, long long result, const char *str)
{
	if (sign > 0)
	{
		if (result < 922337203685477580)
			return (1);
		if (result == 922337203685477580)
		{
			if (*str == '8' || *str == '9')
				return (-1);
			return (1);
		}
		return (-1);
	}
	else
	{
		if (result < 922337203685477580)
			return (1);
		if (result == 922337203685477580)
		{
			if (*str == '9')
				return (0);
			return (1);
		}
		return (0);
	}
}

int			ft_atoi(const char *str)
{
	int					sign;
	long long			result;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (ft_isdigit(*str))
	{
		if (check_overflow(sign, result, str) != 1)
			return (check_overflow(sign, result, str));
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (sign * (int)result);
}
