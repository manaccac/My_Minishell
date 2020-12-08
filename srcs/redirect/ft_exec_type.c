/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:25:42 by frfrey            #+#    #+#             */
/*   Updated: 2020/06/18 08:42:29 by frfrey           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_exec_redir_chi(int fd[2], t_shell *shell, t_redir *redir)
{
	static int		i = 0;

	i += 1;
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	if (redir->type == PIPE)
		ft_exec_prog(redir, shell);
	else if (redir->type == SIMPLE && i != shell->nb_red)
		ft_exec_simple(redir, fd[1]);
	else if (redir->type == DOUBLE && i != shell->nb_red)
		ft_exec_double(redir, fd[1]);
	if (i == shell->nb_red)
		i = 0;
	close(fd[1]);
	exit(EXIT_SUCCESS);
}

static void		ft_exec_master_fa(int fd[2], t_shell *s, t_redir *r, int fds)
{
	static int		i = 0;

	i += 1;
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	if (i == s->nb_red && s->nb_pip > 0)
	{
		if (s->redir->type == SIMPLE)
		{
			ft_exec_simple(r, s->sfd[0]);
		}
		else if (s->redir->type == DOUBLE)
			ft_exec_double(r, s->sfd[0]);
		i = 0;
	}
	exec_master(s, r->next, s->sfd);
	dup2(fds, STDIN_FILENO);
	wait(NULL);
	close(fd[0]);
}

static void		ft_exec_master_simple(t_shell *shell, t_redir *r, int fd[2])
{
	pid_t	pid;

	if (r->type == PIPE)
	{
		pid = fork();
		if (pid == 0)
			ft_exec_prog(r, shell);
		wait(NULL);
	}
	else if (r->type == SIMPLE)
		ft_exec_simple(r, fd[0]);
	else if (r->type == DOUBLE)
		ft_exec_double(r, fd[0]);
	else if (r->type == S_IN)
		get_function(shell->line->function, shell);
}

void			exec_master(t_shell *shell, t_redir *redir, int fd1[2])
{
	pid_t	pid;
	int		fd[2];
	int		back_fd;

	signal(SIGQUIT, signal_child);
	signal(SIGINT, signal_child);
	if (redir && shell->nb_pipe > 1)
	{
		shell->nb_pipe -= 1;
		back_fd = dup(STDIN_FILENO);
		pipe(fd);
		pid = fork();
		if (pid == 0)
			ft_exec_redir_chi(fd, shell, redir);
		ft_exec_master_fa(fd, shell, redir, back_fd);
	}
	else
		ft_exec_master_simple(shell, redir, fd1);
	signal(SIGQUIT, signal_manager);
	signal(SIGINT, signal_manager);
}
