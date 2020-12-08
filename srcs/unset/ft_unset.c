/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 11:11:00 by rpichon           #+#    #+#             */
/*   Updated: 2020/06/16 11:56:02 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unset(t_shell *shell)
{
	t_env	*prev;
	t_env	*actual;
	char	**args;
	int		i;

	i = -1;
	args = ft_split(shell->line->av, ' ');
	errno = 0;
	while (args[++i])
	{
		prev = shell->env;
		while (prev)
		{
			actual = prev->next;
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
	}
}
