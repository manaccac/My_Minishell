/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 11:09:52 by juan              #+#    #+#             */
/*   Updated: 2020/12/11 08:57:49 by manaccac         ###   ########lyon.fr   */
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
		a = chdir(ft_strjoin(ft_cd_tilde(shell->env),
			*ft_split(shell->line->av, '~')));
	else
		a = chdir(shell->line->av);
	if (a == -1)
		ft_printf("minishell: cd: %s: No such file or directory\n",
			shell->line->av);
	else
		errno = 0;
}
