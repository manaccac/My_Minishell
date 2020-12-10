/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:32:20 by rpichon           #+#    #+#             */
/*   Updated: 2020/12/10 08:50:20 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*get_name(char *env)
{
	int		i;
	char	*name;

	i = 0;
	while (env[i] != '=')
		i++;
	name = ft_strndup(env, i);
	return (name);
}

char		*get_val(char *env)
{
	int		i;
	char	*val;

	i = 0;
	while (*env++ != '=')
		;
	while (env[i])
		i++;
	val = ft_strndup(env, i);
	return (val);
}

t_env		*lst_new_env(char *name, char *val)
{
	t_env	*new;

	if (!(new = ft_calloc(1, sizeof(t_env))))
		return (NULL);
	new->name = name;
	new->val = val;
	return (new);
}

t_env		*init_env(char **envp)
{
	int		i;
	t_env	*begin;
	t_env	*last;
	t_env	*new;

	i = 0;
	if (!(begin = lst_new_env(get_name(envp[0]), get_val(envp[0]))))
		return (NULL);
	last = begin;
	while (envp[++i])
	{
		if (!(new = lst_new_env(get_name(envp[i]), get_val(envp[i]))))
			return (NULL);
		last->next = new;
		last = new;
	}
	return (begin);
}
