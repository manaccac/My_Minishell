/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:29:23 by manaccac          #+#    #+#             */
/*   Updated: 2020/12/17 14:29:24 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		print_str_colored(char *str, char *color)
{
	write(1, color, ft_strlen(color));
	write(1, str, ft_strlen(str));
	write(1, _EOFORMAT_, ft_strlen(_EOFORMAT_));
}

void			disp_curdir(void)
{
	char	buf[PATH_MAX];
	int		i;

	i = 0;
	getcwd(buf, PATH_MAX);
	i = ft_strlen(buf);
	while (i && buf[i] != '/')
		i--;
	print_str_colored(buf + i + 1, _BOLD_YELLOW_);
	print_str_colored(" ", 0);
}

void			print_prompt(void)
{
	char	*color;

	color = (errno != 0 ? _BOLD_RED_ : _BOLD_CYAN_);
	print_str_colored("➜ ", color);
	disp_curdir();
}

void			ft_wait_for_command(t_shell *shell)
{
	char		*save;
	char		*line;

	save = ft_strdup("");
	while (get_next_line(0, &line, &save) > 0)
	{
		if (parse_line(line, shell) == 0)
			exit(0);
		print_prompt();
		free(line);
	}
	ft_exit_eof(shell);
}
