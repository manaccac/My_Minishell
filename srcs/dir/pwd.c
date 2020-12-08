/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 11:51:15 by thomasgrang       #+#    #+#             */
/*   Updated: 2020/05/19 14:24:04 by frfrey           ###   ########lyon.fr   */
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
