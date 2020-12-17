/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:30:10 by manaccac          #+#    #+#             */
/*   Updated: 2020/12/17 14:30:11 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_is_char_spe(char c)
{
	if ((c >= 0 && c <= 35) || \
			(c >= 37 && c <= 47) || \
				(c >= 58 && c <= 64) || \
					(c >= 93 && c <= 96) || \
						(c >= 123) || \
							(c == 91))
		return (1);
	return (0);
}

static int		ft_next_word(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] == '\\')
		i++;
	if (line[i] == '$' && line[i + 1] == '?')
		i += 2;
	else if (line[i] == '$')
	{
		i++;
		if (ft_isalpha(line[i]))
			while (line[i] && ft_isalnum(line[i]))
				i++;
		else if (ft_isdigit(line[i]))
			while (line[i] && ft_isdigit(line[i]))
				i++;
	}
	else if (ft_isalnum(line[i]))
		while (line[i] && ft_isalnum(line[i]))
			i++;
	else if (ft_is_char_spe(line[i]))
		while ((line[i]) && ft_is_char_spe(line[i]))
			i++;
	return (i);
}

static t_word	*lst_new_list(char *line)
{
	t_word	*new;
	int		i;

	if (!(new = ft_calloc(1, sizeof(t_word))))
		return (NULL);
	i = ft_next_word(line);
	new->word = ft_strndup(line, i);
	return (new);
}

static t_word	*ft_init_lst_echo(char *line)
{
	int		i;
	t_word	*new;
	t_word	*begin;
	t_word	*last;

	i = 0;
	if (!(begin = lst_new_list(line + i)))
		return (NULL);
	last = begin;
	i += ft_next_word(line);
	while (line[i])
	{
		if (!(new = lst_new_list(line + i)))
			return (NULL);
		last->next = new;
		last = new;
		i += ft_next_word(&line[i]);
	}
	return (begin);
}

void			ft_prepare_lst(char **line, t_env *env, t_echo *pars)
{
	t_word	*lst;
	t_word	*first;

	(*line) = ft_strtrim_free((*line), " \t\n\r\v\f");
	lst = ft_init_lst_echo((*line));
	first = lst;
	ft_prepare_line(pars, env, lst);
	ft_free_echo(first);
}
