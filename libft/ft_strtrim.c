/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:28:04 by gshamika          #+#    #+#             */
/*   Updated: 2019/09/18 21:17:45 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_lws(const char *str)
{
	size_t	ws;
	size_t	i;
	size_t	len;

	ws = 0;
	i = 0;
	len = ft_strlen(str);
	while ((str[i] == ' ' || str[i] == '\t' ||
				str[i] == '\n') && i < len)
	{
		ws++;
		i++;
	}
	return (ws);
}

static size_t	count_rws(const char *str)
{
	size_t	ws;
	size_t	i;
	size_t	len;

	ws = 0;
	i = ft_strlen(str);
	len = ft_strlen(str);
	while ((str[i - 1] == ' ' || str[i - 1] == '\t' ||
				str[i - 1] == '\n') && i > 0)
	{
		ws++;
		i--;
	}
	return (ws);
}

char			*ft_strtrim(const char *s)
{
	char	*dst;
	size_t	lws;
	size_t	rws;
	size_t	i;

	if (!s)
		return (NULL);
	lws = count_lws(s);
	if (lws == ft_strlen(s))
		rws = 0;
	else
		rws = count_rws(s);
	if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen(s) - lws - rws + 1))))
		return (NULL);
	i = lws;
	while (i < (ft_strlen(s) - rws))
	{
		dst[i - lws] = s[i];
		i++;
	}
	dst[i - lws] = '\0';
	return (dst);
}
