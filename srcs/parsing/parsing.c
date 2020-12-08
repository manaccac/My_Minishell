/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:00:11 by frfrey            #+#    #+#             */
/*   Updated: 2020/06/11 10:23:24 by frfrey           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			ft_check_quote(char *line)
{
	int		i;
	char	quote;
	int		bslash;

	i = 0;
	quote = 0;
	bslash = 0;
	while (((line[i]) && line[i] != ';') || \
		(line[i] == ';' && (quote || bslash)))
	{
		if ((line[i] == '"' || line[i] == '\'') && !quote)
			quote = line[i];
		else if ((line[i] == '"' || line[i] == '\'') && quote == line[i])
			quote = 0;
		if (line[i] == '\\' && line[i + 1] == ';')
			bslash = 1;
		else if (line[i] != '\\')
			bslash = 0;
		i++;
	}
	return (i);
}

static char			*ft_get_line(char *line)
{
	int		i;

	i = ft_check_quote(line);
	return (ft_strtrim_free(ft_strndup(line, i), " \t\n\r\v\f"));
}

static t_line		*lst_new_list(char *line)
{
	t_line	*new;
	int		i;

	i = 0;
	if (!(new = ft_calloc(1, sizeof(t_line))))
		return (NULL);
	while (line[i] && line[i] != ' ' && line[i] != ';')
		i++;
	new->function = ft_strtrim_free(ft_strndup(line, i), "'\"");
	new->av = ft_get_line(&line[i]);
	free(line);
	return (new);
}

static t_line		*init_lst(char *line)
{
	int		i;
	t_line	*new;
	t_line	*begin;
	t_line	*last;

	i = 0;
	if (!(begin = lst_new_list(ft_get_line(line + i))))
		return (NULL);
	last = begin;
	i += ft_check_quote(&line[i]);
	if (line[i] == ';')
		i++;
	while (line[i])
	{
		if (!(new = lst_new_list(ft_get_line(line + i))))
			return (NULL);
		last->next = new;
		last = new;
		i += ft_check_quote(&line[i]);
		if (line[i] == ';')
			i++;
	}
	return (begin);
}

int					parse_line(char *line, t_shell *shell)
{
	t_line		*lst;
	t_line		*first;

	shell->forked = 0;
	lst = init_lst(line);
	first = lst;
	while (lst)
	{
		shell->line = lst;
		if (ft_check_redir(shell) == 0)
			return (EXIT_SUCCESS);
		free(lst->function);
		free(lst->av);
		lst = lst->next;
	}
	free(first);
	return (!EXIT_SUCCESS);
}
