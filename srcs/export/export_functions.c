/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:35:33 by rpichon           #+#    #+#             */
/*   Updated: 2020/12/10 08:50:14 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_var_name(char *s)
{
	char	*str;
	int		i;
	int		nb_slash;

	nb_slash = 0;
	i = 0;
	while (s[i] && s[i] != ' ' && !(s[i] == '\\' && s[i + 1] == ' '))
	{
		if (s[i] == '\\' && ++i)
			nb_slash++;
		if (s[++i - 1] == '=' && i--)
			break ;
	}
	str = malloc(sizeof(char) * (i - nb_slash) + 1);
	i = 0;
	while (s && *s && *s != ' ' && !(*s == '\\' && *(s + 1) == ' '))
	{
		if (*s == '\\')
			s++;
		if (*s == '=')
			break ;
		str[i++] = *s++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_val_value(char *s)
{
	char	*str;
	int		i;
	int		nb_slash;

	i = 0;
	nb_slash = 0;
	while (s[i] && s[i] != ' ')
	{
		if (s[i++] == '\\')
		{
			nb_slash++;
			if (s[i] == ' ')
				i++;
		}
	}
	str = malloc(sizeof(char) * (i - nb_slash) + 1);
	i = 0;
	while (*s && *s != ' ')
	{
		if (*s == '\\')
			s++;
		str[i++] = *s++;
	}
	str[i] = '\0';
	return (str);
}

void	addlast_lst(t_env *env, char *name, char *val)
{
	t_env *last;

	last = env;
	while (last->next && ft_strcmp(last->name, name) != 0)
		last = last->next;
	if (ft_strcmp(last->name, name) == 0)
	{
		if (last->val && val && *val)
			free(last->val);
		if (val)
			last->val = val;
	}
	else
		last->next = lst_new_env(name, val);
}
