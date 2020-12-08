/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:32:20 by rpichon           #+#    #+#             */
/*   Updated: 2020/06/16 11:58:56 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		disp_env(t_shell *shell)
{
	t_env	*begin;

	!ft_strcmp(shell->line->function, "env") ? shell->is_export = 0 : 0;
	while (shell->line->av && ft_isspace(*(shell->line->av)))
		shell->line->av++;
	if (shell->line->av && *(shell->line->av) && *(shell->line->av) != ';' &&
		!shell->is_export)
	{
		errno = EINVAL;
		return ;
	}
	begin = shell->env;
	while (begin)
	{
		errno = 0;
		if (shell->is_export)
			if (begin->val)
				ft_printf("declare -x %s=\"%s\"\n", begin->name, begin->val);
			else
				ft_printf("declare -x %s\n", begin->name);
		else if (begin->val && *begin->val)
			ft_printf("%s=%s\n", begin->name, begin->val);
		begin = begin->next;
	}
}