/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:37:36 by gshamika          #+#    #+#             */
/*   Updated: 2019/10/11 18:08:53 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	len1;
	size_t	len2;

	len1 = ft_strplen(s1);
	len2 = ft_strplen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str || (!s1 && !s2))
		return (NULL);
	i = 0;
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		str[i + len1] = s2[i];
		i++;
	}
	str[i + len1] = '\0';
	return (str);
}
