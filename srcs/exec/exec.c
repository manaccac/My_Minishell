/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 11:40:10 by thomasgrang       #+#    #+#             */
/*   Updated: 2020/06/11 11:45:44 by frfrey           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		print_error(int status, t_shell *shell)
{
	if (status == 10752)
	{
		errno = ENOENT;
		ft_printf("minishell: %s: No such file or directory\n", \
			shell->line->function);
	}
	else if (status != 256 && status != 0 && status != 2 && status != 3)
	{
		errno = EPERM;
		ft_printf("minishell: %s: command not found\n", \
			shell->line->function);
	}
}

static void		ft_exec_prog1(t_shell *shell, char **argv)
{
	char	ret[PATH_MAX];
	char	*str;
	int		i;

	if (getcwd(ret, PATH_MAX) == NULL)
		errno = EINVAL;
	str = ft_strdup(ret);
	str = ft_strjoin_free(str, "/");
	str = ft_strjoin_free(str, shell->line->function + 2);
	execve(str, argv, shell->envp);
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
	free(str);
	exit(42);
}

static void		ft_exec_cmd_two(t_shell *shell, char **path, char **argv)
{
	int		i;
	char	*str;

	i = 0;
	while (path[i])
	{
		str = ft_strjoin(path[i], "/");
		str = ft_strjoin_free(str, shell->line->function);
		execve(str, argv, shell->envp);
		free(str);
		free(path[i]);
		i++;
	}
	free(path);
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
	exit(errno);
}

static void		ft_exec_cmd(t_shell *shell)
{
	char **argv;
	char *tmp;
	char **path;

	tmp = ft_strdup(shell->line->function);
	tmp = ft_strjoin_free(tmp, " ");
	tmp = ft_strjoin_free(tmp, shell->line->av);
	argv = ft_split_exec(tmp, " '\"");
	free(tmp);
	if (!ft_strncmp(shell->line->function, "./", 2))
		ft_exec_prog1(shell, argv);
	else
	{
		while (shell->env)
		{
			if (!ft_strcmp("PATH", shell->env->name))
				break ;
			shell->env = shell->env->next;
		}
		path = ft_split_exec(shell->env->val, ":");
		ft_exec_cmd_two(shell, path, argv);
	}
}

void			ft_exec(t_shell *shell)
{
	pid_t	pid;
	int		status;

	errno = 0;
	status = 0;
	signal(SIGQUIT, signal_child);
	signal(SIGINT, signal_child);
	if ((pid = fork()) == -1)
		write(1, "minishell: Error: create a fork\n", 32);
	if (pid == 0)
		ft_exec_cmd(shell);
	wait(&status);
	print_error(status, shell);
	if (status > 3)
		errno = status / 256;
	else
		errno = status;
	signal(SIGQUIT, signal_manager);
	signal(SIGINT, signal_manager);
}
