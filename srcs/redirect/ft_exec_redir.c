/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 10:41:18 by frfrey            #+#    #+#             */
/*   Updated: 2020/06/18 08:37:15 by frfrey           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_exec_father(t_shell *shell, int fd[2])
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	exec_master(shell, shell->redir, fd);
}

static void		ft_exec_child(t_shell *shell, int fd[2])
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	if (shell->redir->type == S_IN)
		ft_exec_s_in(shell->redir, fd[1]);
	else
		get_function(shell->line->function, shell);
	close(fd[1]);
	exit(EXIT_SUCCESS);
}

int				ft_pipe(t_shell *shell)
{
	pid_t	pid;
	int		back_fd;
	int		fd[2];

	back_fd = dup(STDIN_FILENO);
	pipe(fd);
	shell->sfd = fd;
	pid = fork();
	if (pid == 0)
		ft_exec_child(shell, fd);
	ft_exec_father(shell, shell->sfd);
	dup2(back_fd, STDIN_FILENO);
	wait(NULL);
	close(fd[0]);
	return (!EXIT_SUCCESS);
}
