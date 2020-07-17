/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:19:53 by gshamika          #+#    #+#             */
/*   Updated: 2019/09/16 09:45:32 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;

	index = ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == c)
			return ((char*)&s[index]);
		index--;
	}
	return (NULL);
}
