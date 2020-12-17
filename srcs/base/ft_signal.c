/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:29:34 by manaccac          #+#    #+#             */
/*   Updated: 2020/12/17 14:29:35 by manaccac         ###   ########lyon.fr   */
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
