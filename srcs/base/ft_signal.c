/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 15:11:51 by frfrey            #+#    #+#             */
/*   Updated: 2020/06/04 16:56:14 by frfrey           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			signal_child(int sig)
{
	if (sig == SIGINT || sig == SIGQUIT)
	{
		if (sig == 3)
			ft_printf("Quit: %d", sig);
		write(1, "\n", 1);
		errno = sig;
	}
}

void			signal_manager(int sig)
{
	static int		pid;

	ft_printf("\b\b  \b\b");
	if (sig == 0 || sig > 32)
	{
		pid = sig;
		return ;
	}
	if (sig == SIGINT || sig == SIGQUIT)
	{
		if (pid)
		{
			kill(pid, sig);
			if (sig == SIGQUIT)
				ft_printf("Quit: %d\n", pid);
		}
		write(1, "\n", 1);
		errno = (sig == SIGINT) ? 1 : 0;
		print_prompt();
	}
}
