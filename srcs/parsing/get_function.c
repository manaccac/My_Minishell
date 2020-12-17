/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:32:21 by manaccac          #+#    #+#             */
/*   Updated: 2020/12/17 14:32:22 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_remove_tab(char **tab, int value)
{
	int		nb;

	nb = 0;
	while (tab[nb])
		free(tab[nb++]);
	free(tab);
	return (value);
}

static char		**ft_init_tab(void)
{
	char	**tab;

	if (!(tab = malloc(sizeof(char *) * 8)))
		return (NULL);
	tab[0] = ft_strdup("pwd");
	tab[1] = ft_strdup("cd");
	tab[2] = ft_strdup("env");
	tab[3] = ft_strdup("exit");
	tab[4] = ft_strdup("export");
	tab[5] = ft_strdup("unset");
	tab[6] = ft_strdup("echo");
	tab[7] = NULL;
	return (tab);
}

int				get_function(char *function, t_shell *shell)
{
	void	(*tab_function[7])(t_shell *);
	char	**tab;
	int		i;

	i = -1;
	tab_function[0] = ft_pwd;
	tab_function[1] = ft_change_dir;
	tab_function[2] = disp_env;
	tab_function[3] = ft_exit;
	tab_function[4] = ft_export;
	tab_function[5] = ft_unset;
	tab_function[6] = print_echo;
	if ((tab = ft_init_tab()) == NULL)
		return (ft_remove_tab(tab, !EXIT_FAILURE));
	while (++i < 7)
		if (!ft_strcmp(tab[i], function))
		{
			tab_function[i](shell);
			break ;
		}
	if (i == 7 && shell->line->function[0] != 0)
		ft_exec(shell);
	return (ft_remove_tab(tab, !EXIT_SUCCESS));
}
