/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:33:30 by manaccac          #+#    #+#             */
/*   Updated: 2020/12/17 14:33:30 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*ft_while_unset(t_env *prev, t_env *actual, char **args, int i)
{
	while (prev)
	{
		if (prev->next)
			actual = prev->next;
		else
			break ;
		if (!ft_strcmp(actual->name, args[i]))
		{
			prev->next = actual->next;
			if (actual->val)
				free(actual->val);
			free(actual->name);
			free(actual);
		}
		prev = prev->next;
	}
	return (prev);
}

void	ft_unset(t_shell *shell)
{
	t_env	*prev;
	t_env	*actual;
	char	**args;
	int		i;

	i = -1;
	actual = NULL;
	args = ft_split(shell->line->av, ' ');
	errno = 0;
	while (args[++i])
	{
		if (ft_strcmp("=", args[i]) == 0)
			ft_printf("bash: unset: `=': not a valid identifier\n");
		prev = shell->env;
		prev = ft_while_unset(prev, actual, args, i);
	}
}
