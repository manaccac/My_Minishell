/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 11:27:37 by frfrey            #+#    #+#             */
/*   Updated: 2020/06/17 10:46:39 by frfrey           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(int status)
{
	if (status == 10752)
	{
		errno = ENOENT;
		ft_printf("minishell: No such file or directory\n");
	}
	else if (status != 256 && status != 0 && status != 2 && status != 3)
	{
		errno = EPERM;
		ft_printf("minishell: command not found\n");
	}
}

static void	ft_exec_prog1(char **argv, t_shell *shell)
{
	char	ret[PATH_MAX];
	char	*str;
	int		i;

	if (getcwd(ret, PATH_MAX) == NULL)
		errno = EINVAL;
	str = ft_strdup(ret);
	str = ft_strjoin_free(str, "/");
	str = ft_strjoin_free(str, argv[0]);
	execve(str, argv, shell->envp);
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
	free(str);
	exit(42);
}

static void	ft_exec_cmd_two(t_shell *shell, char **path, char **argv)
{
	int		i;
	char	*str;

	i = 0;
	while (path[i])
	{
		str = ft_strjoin(path[i], "/");
		str = ft_strjoin_free(str, argv[0]);
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

static void	ft_exec_cmd(t_redir *redir, t_shell *shell)
{
	char **argv;
	char **path;

	argv = ft_split_exec(redir->path, " '\"");
	if (!ft_strncmp(argv[0], "./", 2))
		ft_exec_prog1(argv, shell);
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

void		ft_exec_prog(t_redir *redir, t_shell *shell)
{
	int		status;

	errno = 0;
	status = 0;
	ft_exec_cmd(redir, shell);
	print_error(status);
	if (status > 3)
		errno = status / 256;
	else
		errno = status;
}
