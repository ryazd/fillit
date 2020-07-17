/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:28:35 by gshamika          #+#    #+#             */
/*   Updated: 2019/09/10 13:45:09 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*str_dst;
	char	*str_src;

	str_dst = (char *)dst;
	str_src = (char *)src;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			str_dst[i] = str_src[i];
			i++;
		}
	}
	else if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			str_dst[i - 1] = str_src[i - 1];
			i--;
		}
	}
	return (dst);
}
