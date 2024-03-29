/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:33:11 by manaccac          #+#    #+#             */
/*   Updated: 2020/12/17 14:33:11 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			ft_is_redirect(char *line)
{
	if (line[0] == '|')
		return (1);
	else if (line[0] == '>')
		return (1);
	else if (line[0] == '<')
		return (1);
	return (0);
}

int					ft_check_redir(t_shell *shell)
{
	char	*tmp;

	tmp = chredir(shell->line->av, shell);
	if (tmp)
	{
		shell->redir = init_lst_redir(tmp);
		free(tmp);
		shell->nb_pipe = count_redir(shell->redir, shell);
		if (ft_pipe(shell) == 0)
			return (!EXIT_FAILURE);
	}
	else if (ft_is_redirect(shell->line->av))
	{
		shell->redir = init_lst_redir(shell->line->av);
		shell->nb_pipe = count_redir(shell->redir, shell);
		free(shell->line->av);
		shell->line->av = ft_strdup("");
		if (ft_pipe(shell) == 0)
			return (!EXIT_FAILURE);
	}
	else if (get_function(shell->line->function, shell) == 0)
		return (!EXIT_FAILURE);
	return (!EXIT_SUCCESS);
}
