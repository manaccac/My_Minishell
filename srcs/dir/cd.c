/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 11:09:52 by juan              #+#    #+#             */
/*   Updated: 2020/06/16 11:57:55 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char		*ft_cd_tilde(t_env *env)
{
	while (env)
	{
		if (ft_strcmp("HOME", env->name) == 0)
			return (env->val);
		env = env->next;
	}
	return (NULL);
}

void			ft_change_dir(t_shell *shell)
{
	int a;

	a = 0;
	if (shell->line->av[0] == '~' || shell->line->av[0] == '\0')
		a = chdir(ft_cd_tilde(shell->env));
	else
		a = chdir(shell->line->av);
	if (a == -1)
		ft_printf("minishell: cd: %s: No such file or directory\n",
			shell->line->av);
	else
		errno = 0;
}
