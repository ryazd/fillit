/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:31:31 by gshamika          #+#    #+#             */
/*   Updated: 2019/09/16 17:19:46 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		max_len;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	max_len = ft_strlen(haystack) - ft_strlen(needle);
	while (i <= max_len)
	{
		if (*haystack == *needle)
		{
			j = 0;
			while (haystack[j] == needle[j])
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
