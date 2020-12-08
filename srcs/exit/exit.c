/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:42:07 by frfrey            #+#    #+#             */
/*   Updated: 2020/06/16 12:06:51 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ft_exit_error(t_shell *shell, int i)
{
	if (i == 1)
	{
		ft_printf("minishell: exit: %s: numeric argument required\n"
		, shell->line->av);
		free_env(shell->env);
		exit(255);
	}
	else
		ft_printf("minishell: exit: too many arguments\n");
}

static int			ft_check_argv(t_shell *shell)
{
	int		i;

	i = 0;
	while (shell->line->av[i])
	{
		if (shell->line->av[i] == ' ' && shell->line->av[i + 1])
		{
			ft_exit_error(shell, 2);
			return (EXIT_FAILURE);
		}
		if (shell->line->av[i] == '-' &&
			(shell->line->av[i + 1] < '0' || shell->line->av[i + 1] > '9'))
			ft_exit_error(shell, 1);
		else if (shell->line->av[i] == '+' &&
			(shell->line->av[i + 1] < '0' || shell->line->av[i + 1] > '9'))
			ft_exit_error(shell, 1);
		else if ((shell->line->av[i] < '0' || shell->line->av[i] > '9') &&
			(shell->line->av[i] != '-') && (shell->line->av[i] != '+'))
			ft_exit_error(shell, 1);
		i++;
	}
	return (EXIT_SUCCESS);
}

void				ft_exit(t_shell *shell)
{
	unsigned char ex;

	ex = 0;
	ft_printf("exit\n");
	if (ft_check_argv(shell))
		return ;
	if ((long long)ft_atoi_size_t(shell->line->av) > LLONG_MAX
		|| (long long)ft_atoi_size_t(shell->line->av) < LLONG_MIN)
		ft_exit_error(shell, 1);
	ex = ft_atoi(shell->line->av);
	free_env(shell->env);
	exit(ex);
}

void				ft_exit_eof(t_shell *shell)
{
	unsigned char ex;

	ex = 0;
	ft_printf("exit\n");
	free_env(shell->env);
	exit(ex);
}
