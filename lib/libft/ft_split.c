/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:33:18 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:33:19 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	int words;
	int i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
		{
			words++;
			i++;
		}
		else
			i++;
	}
	return (words);
}

static char		*ft_strdup_sep(const char *s1, char c)
{
	char	*str;
	int		len_word;

	len_word = 0;
	while (s1[len_word] != c && s1[len_word])
		len_word++;
	if (!(str = malloc(sizeof(char) * len_word + 1)))
		return (0);
	ft_memcpy(str, s1, len_word);
	str[len_word] = '\0';
	return (str);
}

static char		**free_if_error(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**new_str;
	int		letters;
	int		index;
	int		i;

	if (!s)
		return (0);
	i = 0;
	index = 0;
	if (!(new_str = malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (0);
	new_str[count_words(s, c)] = NULL;
	while (s[i])
		if (s[i] == c)
			i++;
		else
		{
			letters = 0;
			while (s[i + letters] != c && s[i + letters])
				letters++;
			if (!(new_str[index++] = ft_strdup_sep(s + i, c)))
				return (free_if_error(new_str));
			i += letters;
		}
	return (new_str);
}
