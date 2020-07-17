/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshamika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:52:46 by gshamika          #+#    #+#             */
/*   Updated: 2019/09/18 21:13:44 by gshamika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s, char c)
{
	int		words;

	words = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			words++;
		s++;
	}
	return (words);
}

static int	count_symbols(char *s, char c, int word)
{
	int		i;
	int		i_start;
	int		cur_word;

	i = 0;
	cur_word = 0;
	while (cur_word < word)
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			cur_word++;
		i++;
	}
	i_start = i - 1;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i - i_start);
}

static char	*get_word(char *s, char c, int len, int word)
{
	int		i;
	int		cur_word;

	i = 0;
	cur_word = 0;
	while (cur_word < word)
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			cur_word++;
		i++;
	}
	i--;
	return (ft_strsub(s, i, len));
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ar;
	int		ws;
	int		ls;
	int		i;

	if (!s)
		return (NULL);
	ws = count_words((char *)s, c);
	if (!(ar = (char **)malloc(sizeof(char *) * (ws + 1))))
		return (NULL);
	i = 0;
	while (i <= ws)
	{
		ls = (i < ws ? count_symbols((char *)s, c, (i + 1)) : 0);
		ar[i] = (i < ws ? (char *)malloc(sizeof(char) * (ls + 1)) : NULL);
		if (i < ws && !ar[i])
		{
			ft_freearray(ar, i);
			return (NULL);
		}
		ar[i] = (i < ws ? get_word((char *)s, c, ls, (i + 1)) : NULL);
		i++;
	}
	return (ar);
}
