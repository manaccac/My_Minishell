/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:32:20 by rpichon           #+#    #+#             */
/*   Updated: 2020/06/02 18:14:18 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_env	*cp_lst(t_env *env)
{
	t_env	*begin_tmp;
	t_env	*last;
	t_env	*new;

	begin_tmp = lst_new_env(ft_strdup(env->name), ft_strdup(env->val));
	last = begin_tmp;
	env = env->next;
	while (env)
	{
		if (!(new = lst_new_env(ft_strdup(env->name), ft_strdup(env->val))))
			return (NULL);
		last->next = new;
		last = new;
		env = env->next;
	}
	return (begin_tmp);
}

static void		ft_swap(t_env *t1, t_env *t2)
{
	char	*tmp;

	tmp = t1->name;
	t1->name = t2->name;
	t2->name = tmp;
	tmp = t1->val;
	t1->val = t2->val;
	t2->val = tmp;
}

void			free_env(t_env *env)
{
	t_env	*prev;

	prev = env;
	while (env)
	{
		env = env->next;
		free(prev->name);
		free(prev->val);
		free(prev);
		prev = env;
	}
}

void			export_sort(t_shell *shell)
{
	t_env	*tmp;
	t_env	*begin_tmp;
	t_env	*next;
	t_env	*save_env;

	errno = 0;
	save_env = shell->env;
	begin_tmp = cp_lst(shell->env);
	tmp = begin_tmp;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (ft_strcmp(tmp->name, next->name) > 0)
				ft_swap(tmp, next);
			next = next->next;
		}
		tmp = tmp->next;
	}
	shell->is_export = 1;
	shell->env = begin_tmp;
	disp_env(shell);
	shell->env = save_env;
	free_env(begin_tmp);
}
