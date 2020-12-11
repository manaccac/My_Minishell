/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 09:57:04 by frfrey            #+#    #+#             */
/*   Updated: 2020/12/11 09:24:17 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(int ac, char **av, char **envp)
{
	t_env		*env;
	t_shell		shell;

	if (ac >= 2)
	{
		ft_printf("just launch ./minishell\n");
		return (127);
	}
	(void)ac;
	(void)av;
	shell.envp = envp;
	env = init_env(envp);
	shell.env = env;
	errno = 0;
	print_prompt();
	signal(SIGQUIT, signal_manager);
	signal(SIGINT, signal_manager);
	ft_wait_for_command(&shell);
	return (EXIT_SUCCESS);
}
