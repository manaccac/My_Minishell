/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:26:52 by frfrey            #+#    #+#             */
/*   Updated: 2020/06/18 18:25:51 by frfrey           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_exec_simple(t_redir *redir, int fd)
{
	int		tmp;
	char	*line;
	char	*save;

	save = ft_strdup("");
	if ((tmp = open(redir->path, O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0)
		printf("Error:\nWhen you redirect on file whith >");
	while (get_next_line(fd, &line, &save) > 0)
	{
		write(tmp, line, ft_strlen(line));
		write(tmp, "\n", 1);
		free(line);
	}
	if (line && *line)
	{
		dprintf(tmp, line, ft_strlen(line));
		free(line);
	}
	close(tmp);
}

void		ft_exec_double(t_redir *redir, int fd)
{
	int		tmp;
	char	*line;
	char	*save;

	save = ft_strdup("");
	if ((tmp = open(redir->path, O_RDWR | O_CREAT | O_APPEND, 0644)) < 0)
		printf("Error:\nWhen you redirect on file whith >>");
	while (get_next_line(fd, &line, &save) > 0)
	{
		write(tmp, line, ft_strlen(line));
		write(tmp, "\n", 1);
		free(line);
	}
	if (line && *line)
	{
		dprintf(tmp, line, ft_strlen(line));
		free(line);
	}
	close(tmp);
}

void		ft_exec_s_in(t_redir *redir, int fd)
{
	int		tmp;
	char	*line;
	char	*save;

	save = ft_strdup("");
	if ((tmp = open(redir->path, O_RDWR)) < 0)
		printf("Error:\nWhen you redirect on file whith <");
	while (get_next_line(tmp, &line, &save) > 0)
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	if (line && *line)
	{
		dprintf(fd, line, ft_strlen(line));
		free(line);
	}
	close(tmp);
}
