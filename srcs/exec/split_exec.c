/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:31:15 by manaccac          #+#    #+#             */
/*   Updated: 2020/12/17 14:31:16 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_separator(char c, char *chrst)
{
	int i;

	i = 0;
	while (chrst[i])
	{
		if (chrst[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		count_words(char *str, char *chrst)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] && !is_separator(str[i], chrst))
			cpt++;
		while (!is_separator(str[i + 1], chrst)
				&& str[i] && str[i + 1] != '\0')
			i++;
		i++;
		while (str[i] && (is_separator(str[i], chrst)))
			i++;
	}
	return (cpt);
}

static int		ft_strlen_split(char *str, char *chrst)
{
	int i;

	i = 0;
	while (str[i] && !is_separator(str[i], chrst))
		i++;
	return (i);
}

char			**ft_split_exec(char *str, char *chrst)
{
	char		**rep;
	int			i;
	int			j;

	i = -1;
	rep = malloc(sizeof(rep) * (count_words(str, chrst) + 1));
	while (*str)
	{
		j = 0;
		if (!is_separator(*str, chrst))
		{
			rep[++i] = malloc(sizeof(char) * (ft_strlen_split(str, chrst) + 1));
			while (*str && !is_separator(*str, chrst))
			{
				rep[i][j] = *str;
				str++;
				j++;
			}
			rep[i][j] = '\0';
		}
		while (is_separator(*str, chrst))
			str++;
	}
	rep[i + 1] = NULL;
	return (rep);
}
