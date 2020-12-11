/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:32:20 by rpichon           #+#    #+#             */
/*   Updated: 2020/12/11 09:27:51 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_env_while(t_env *begin, t_shell *shell)
{
	if (shell->is_export)
		if (begin->val)
			ft_printf("declare -x %s=\"%s\"\n", begin->name, begin->val);
		else
			ft_printf("declare -x %s\n", begin->name);
	else if (begin->val && *begin->val)
		ft_printf("%s=%s\n", begin->name, begin->val);
	else if (begin->val)
		ft_printf("%s=\n", begin->name);
}

void		disp_env(t_shell *shell)
{
	t_env	*begin;

	!ft_strcmp(shell->line->function, "env") ? shell->is_export = 0 : 0;
	while (shell->line->av && ft_isspace(*(shell->line->av)))
		shell->line->av++;
	if (shell->line->av && *(shell->line->av) && *(shell->line->av) != ';' &&
		!shell->is_export)
	{
		if (shell->line->av)
			ft_printf("env: %s: No sush file or directory\n", shell->line->av);
		errno = EINVAL;
		return ;
	}
	begin = shell->env;
	while (begin)
	{
		errno = 0;
		ft_env_while(begin, shell);
		begin = begin->next;
	}
}
