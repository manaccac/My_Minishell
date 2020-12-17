/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:29:55 by manaccac          #+#    #+#             */
/*   Updated: 2020/12/17 14:29:56 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_shell *shell)
{
	char	ret[PATH_MAX];

	(void)shell;
	if (getcwd(ret, PATH_MAX) == NULL)
		errno = EINVAL;
	ft_printf("%s\n", ret);
	errno = 0;
}
