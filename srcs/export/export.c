/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edepauw <edepauw@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:31:49 by manaccac          #+#    #+#             */
/*   Updated: 2021/02/10 11:48:00 by edepauw          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
int		ft_isalum(int c)
{
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
	 (c >= '0' && c <= '9') || c == '/'|| c == '.'|| c == ':'))
		return (0);
	return (1);
}

static int	check_arg(char *str)
{
	int i;

	i = -1;
	dprintf(1, "str: %s\n", str);
	if (!ft_isalpha(*str) && !(*str == '\\' && ft_isalpha(*(str + 1))))
		return (1);
	while (str[++i])
	{
		if (str[i] == ' ' && str[i - 1] != '\\')
			return (0);
		dprintf(1, "i = %d\n", i);
		dprintf(1, "!%d && !(%d && %d) && %d = %d\n", ft_isalum(str[i]), str[i] == '\\', ft_isalum(str[i + 1]), str[i] != '=', !(ft_isalum(str[i]) && !(str[i] == '\\' && ft_isalum(str[i + 1])))
		&& str[i] != '=');
		if (!ft_isalum(str[i]) && !(str[i] == '\\' && ft_isalum(str[i + 1]))
		&& str[i] != '=')
			return (1);
	}
	return (0);
}

static int	print_arg_err(char *arg)
{
	int i;

	i = 0;
	ft_printf("bash: export: `");
	errno = EINVAL;
	while (arg[i] != ' ' && arg[i])
	{
		if (arg[i] == '\\')
			i++;
		write(1, &arg[i], 1);
		if (arg[i])
			i++;
	}
	ft_printf("': not a valid identifier\n");
	return (i);
}

static void	get_values(t_shell *shell, char *arg)
{
	char	*var_name;
	char	*val_value;

	var_name = get_var_name(arg);
	while (*arg && *arg != ' ' && *arg != '=')
		arg++;
	if (*arg == '=')
	{
		arg++;
		val_value = get_val_value(arg);
		addlast_lst(shell->env, var_name, val_value);
		while (*arg && *arg != ' ')
			if (*arg++ == '\\' && *arg == ' ')
				arg++;
	}
	else
		addlast_lst(shell->env, var_name, 0);
	errno = 0;
}

void		ft_export(t_shell *shell)
{
	char	*arg;

	shell->line->av = rm_quotes_free(shell->line->av, 0, 0, 0);
	arg = shell->line->av;
	if (!*arg)
		export_sort(shell);
	else
		while (*arg)
		{
			while (*arg == ' ')
				arg++;
			if (check_arg(arg))
				arg += print_arg_err(arg);
			else
			{
				get_values(shell, arg);
				while (*arg && *arg != ' ' && *arg != '=')
					arg++;
				if (*arg == '=')
					while (*arg && *arg != ' ')
						if (*arg++ == '\\' && *arg == ' ')
							arg++;
			}
		}
}
