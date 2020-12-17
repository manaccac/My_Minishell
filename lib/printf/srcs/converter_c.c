/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:35:06 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:35:07 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		printf_c(t_listpf *alst, va_list params)
{
	int	c;
	int	size;

	if (alst->f)
		gest_flags_c(alst, params);
	size = alst->spaces;
	if (alst->spaces > 0)
		while (alst->spaces && alst->spaces-- > 1)
			write(1, " ", 1);
	if (alst->type == 'c')
	{
		c = va_arg(params, int);
		write(1, &c, 1);
	}
	else if (alst->type == '%')
		write(1, "%", 1);
	if (alst->spaces < 0)
		while (alst->spaces++ < -1)
			write(1, " ", 1);
	if (size >= 0)
		return ((size > 1) ? size : 1);
	return ((size < 1) ? -size : 1);
}

void	gest_flags_c(t_listpf *alst, va_list params)
{
	if (*(alst->f) == '-' || ft_isdigit(*(alst->f)) || *(alst->f) == '*')
	{
		alst->hyphen = (*(alst->f) == '-') ? 1 : 0;
		while (*(alst->f) == '-')
			alst->f++;
		if (*(alst->f) != '*')
			alst->spaces = ft_atoi(alst->f);
		else
			alst->spaces = va_arg(params, int);
		if (alst->hyphen && alst->hyphen-- && alst->spaces > 0)
			alst->spaces *= -1;
		while (*(alst->f) != '.' && *(alst->f) != '\0')
			alst->f++;
	}
}
