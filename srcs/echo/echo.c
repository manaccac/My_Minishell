/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:34:46 by frfrey            #+#    #+#             */
/*   Updated: 2020/12/08 10:02:32 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_free_echo(t_word *lst)
{
	t_word	*prev;

	prev = lst;
	while (lst)
	{
		lst = lst->next;
		free(prev->word);
		free(prev);
		prev = lst;
	}
	free(prev);
}

void			print_echo(t_shell *shell)
{
	char	*tmp;
	t_echo	echo;
	int		i;

	echo.option = 0;
	echo.quote = 0;
	echo.space = 0;
	echo.i = 0;
	echo.y = 0;
	i = 0;
	shell->echo = &echo;
	i += parse_argument_echo(shell->line->av, \
		&shell->echo->option);
	tmp = ft_strtrim(shell->line->av + i, " \t\n\r\v\f");
	ft_prepare_lst(&tmp, shell->env, shell->echo);
	free(tmp);
	errno = 0;
}
