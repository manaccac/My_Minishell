/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 15:15:51 by juan              #+#    #+#             */
/*   Updated: 2020/06/17 14:48:25 by frfrey           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*ft_strdup_quote(char *s, int a, int b)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	j = 0;
	if (!(dup = (char*)malloc(sizeof(char) * (int)(ft_strlen(s)) + 1)))
		return (NULL);
	while (s[j])
	{
		if (j != a && j != b)
		{
			dup[i] = s[j];
			i++;
			j++;
		}
		else
			j++;
	}
	dup[i] = '\0';
	return (dup);
}

static int		count_quote(char *str, int *pos_a)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			*pos_a = i;
			i = -1;
		}
		if (i == -1)
			i = (int)ft_strlen(str) - 1;
		i++;
	}
	return (i);
}

char			*remove_double_quote(char *str)
{
	char	*ret;
	int		pos_a;
	int		pos_b;
	int		i;

	pos_a = 0;
	i = count_quote(str, &pos_a);
	pos_b = 0;
	if (pos_a != (int)ft_strlen(str))
		pos_b = ft_intchr(str, str[pos_a], pos_a + 1);
	if (str[pos_a] != str[pos_b] || (pos_a == 0 && pos_b == 0))
	{
		pos_a = -1;
		pos_b = -1;
		return (str);
	}
	ret = ft_strdup_quote(str, pos_a, pos_b);
	i = 0;
	while (ret[i])
	{
		if (ret[i] == '\'' || ret[i] == '"')
			return (remove_double_quote(ret));
		i++;
	}
	return (ret);
}
