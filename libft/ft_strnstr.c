/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:31:31 by gshamika          #+#    #+#             */
/*   Updated: 2019/09/17 19:07:12 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	int		max_len;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	max_len = (int)ft_strlen(haystack) - (int)ft_strlen(needle);
	while ((i <= max_len) && (i <= (int)len))
	{
		if (*haystack == *needle)
		{
			j = 0;
			while ((i + j < (int)len) && (haystack[j] == needle[j]))
			{
				if ((haystack[j] == '\0' && needle[j] == '\0') ||
						(needle[j + 1] == '\0'))
					return ((char *)haystack);
				j++;
			}
		}
		haystack++;
		i++;
	}
	return (NULL);
}
