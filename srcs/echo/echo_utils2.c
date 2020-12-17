/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:30:22 by manaccac          #+#    #+#             */
/*   Updated: 2020/12/17 14:30:22 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_print_name_env(t_word *word, t_echo *o)
{
	int		y;

	y = 0;
	if (word->word[y] == '\\')
		y++;
	ft_printf("%s", &word->word[y]);
	o->space = 1;
	return (1);
}

int			ft_print_env(int fd, t_env *env, t_word *word, t_echo *o)
{
	int		i;
	int		y;

	y = 0;
	if (word->word[y] == '\\')
		y++;
	if (word->word[y] == '$')
		y++;
	i = ft_strlen(&word->word[y]) + 1;
	while (env)
	{
		if (ft_strncmp(env->name, &word->word[y], i) == 0)
		{
			write(fd, env->val, ft_strlen(env->val));
			return (1);
		}
		env = env->next;
	}
	o->space = 1;
	return (1);
}

int			ft_print_env2(t_env *env, t_word *word, t_echo *o)
{
	int		i;
	int		y;

	y = 0;
	if (word->word[y] == '\\')
	{
		write(1, "\\", 1);
		y += 2;
	}
	if (word->word[y] == '$')
		y++;
	i = ft_strlen(&word->word[y]) + 1;
	while (env)
	{
		if (ft_strncmp(env->name, &word->word[y], i) == 0)
		{
			write(1, env->val, ft_strlen(env->val));
			return (1);
		}
		env = env->next;
	}
	o->space = 1;
	return (1);
}

int			last_check(t_env *env, t_word *word, t_echo *o)
{
	if ((!o->quote || o->quote == '"') && (word->word[o->i] == '\\' \
		&& word->word[o->i + 1] == '\\'))
	{
		if (word->word[o->i + 1] != '\0' && word->word[o->i + 2] == '$')
			return (ft_print_env2(env, word, o));
	}
	return (0);
}

int			ft_check_is_env(t_env *env, t_word *word, t_echo *o)
{
	if ((o->quote == '"' || !o->quote) && word->word[o->i] == '$' && \
			word->word[o->i + 1] == '?')
	{
		ft_putnbr_fd(errno, 1);
		return (1);
	}
	else if (word->word[o->i] == '$' && word->word[o->i + 1] == '\0')
	{
		write(1, &word->word[o->i], 1);
		return (1);
	}
	else if ((o->quote == '"' || !o->quote) && word->word[o->i] == '$')
	{
		o->space = 0;
		return (ft_print_env(1, env, word, o));
	}
	else if ((!o->quote || o->quote) && ((word->word[o->i] == '\\' && \
			word->word[o->i + 1] == '$')))
	{
		o->space = 0;
		return (ft_print_name_env(word, o));
	}
	return (last_check(env, word, o));
}
