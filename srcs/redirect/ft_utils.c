/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:33:15 by manaccac          #+#    #+#             */
/*   Updated: 2020/12/17 14:33:16 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ft_check_next(char *line)
{
	int		i;
	int		quote;

	i = 0;
	quote = 0;
	while (line[i] && (line[i] == '>' || line[i] == '<' || line[i] == '|'))
		i++;
	while (line[i])
	{
		if ((line[i] == '"' || line[i] == '\'')\
			&& !quote)
			quote = line[i];
		else if (line[i] && line[i] == quote)
			quote = 0;
		else if ((line[i] == '>' || line[i] == '|' \
			|| line[i] == '<') && !quote)
			return (i);
		i++;
	}
	return (i);
}

static int			ft_check_quote(char *line)
{
	int		i;
	int		quote;

	i = 0;
	quote = 0;
	while (line[i])
	{
		if ((line[i] == '"' || line[i] == '\'')\
			&& !quote)
			quote = line[i];
		else if (line[i] && line[i] == quote)
			quote = 0;
		else if ((line[i] == '>' || line[i] == '|' \
			|| line[i] == '<') && !quote)
			return (i);
		i++;
	}
	return (0);
}

char				*chredir(char *line, t_shell *shell)
{
	int		i;
	char	*tmp;

	i = ft_check_quote(line);
	if (i)
	{
		tmp = ft_strdup(line + i);
		shell->line->av = ft_strndup_f(shell->line->av, i);
		return (tmp);
	}
	return (NULL);
}

int					count_redir(t_redir *redir, t_shell *shell)
{
	int		i;

	i = 0;
	shell->nb_red = 0;
	shell->nb_pip = 0;
	while (redir)
	{
		if (redir->type == DOUBLE || redir->type == SIMPLE)
			shell->nb_red += 1;
		if (redir->type == PIPE)
			shell->nb_pip += 1;
		i += 1;
		redir = redir->next;
	}
	return (i);
}
