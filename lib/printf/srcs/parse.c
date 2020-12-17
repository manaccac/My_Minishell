/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:35:42 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:35:42 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse_format(t_listpf **alst, char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i++;
			str += init_parse_lst(alst, str);
		}
		else
			str++;
	}
	return (i);
}

int		init_parse_lst(t_listpf **alst, char *str)
{
	int		i;
	char	*flags;

	i = 0;
	while (!is_converter_pf(str[i]))
		i++;
	flags = ft_substr((const char *)str, 0, i);
	ft_lstnew_addback(alst, flags, str[i]);
	free(flags);
	return (i + 1);
}

int		is_converter_pf(char c)
{
	char	*str;

	str = CONVERTERS;
	while (*str)
	{
		if (c == *str)
			return (TRUE);
		str++;
	}
	return (FALSE);
}

int		ft_disp_elem(t_listpf **alst, va_list params)
{
	int			cpt;
	t_listpf	*lst;

	lst = *alst;
	if (lst->type == 's')
		cpt = printf_str(lst, params);
	if (lst->type == 'd' || lst->type == 'i')
		cpt = printf_d(lst, params);
	if (lst->type == 'u')
		cpt = printf_u(lst, params);
	if (lst->type == 'c' || lst->type == '%')
		cpt = printf_c(lst, params);
	if (lst->type == 'x' || lst->type == 'X')
		cpt = printf_x(lst, params);
	if (lst->type == 'p')
		cpt = printf_p(lst, params);
	lstdel_first(alst);
	return (cpt);
}
