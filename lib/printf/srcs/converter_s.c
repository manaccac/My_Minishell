/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:29:42 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/25 17:52:10 by frfrey           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int		printf_str(t_listpf *alst, va_list params)
{
	char	*str;
	int		i;
	int		size;

	alst->f ? gest_flags_str(alst, params) : 0;
	str = va_arg(params, char *);
	!str ? str = ft_strdup("(null)") : 0;
	size = alst->spaces;
	i = 0;
	while (str[i])
		i++;
	if (alst->precision && alst->nb_precision >= 0)
		i > alst->nb_precision ? i = alst->nb_precision : 0;
	while (alst->spaces > 0 && alst->spaces-- > i)
		write(1, " ", 1);
	!str ? write(1, "(null)", i) : write(1, str, i);
	size = (size < alst->spaces) ? alst->spaces : size;
	while (alst->spaces < 0 && alst->spaces++ < -i)
		write(1, " ", 1);
	!ft_memcmp(str, "(null)", 6) ? free(str) : 0;
	if (size >= 0)
		return (size > i ? size : i);
	return (-size > i ? -size : i);
}

void	gest_flags_str(t_listpf *alst, va_list params)
{
	if (*(alst->f) == '-' || ft_isdigit(*(alst->f)) || *(alst->f) == '*')
	{
		alst->hyphen = (*(alst->f) == '-' && alst->f++) ? 1 : 0;
		while (*(alst->f) == '-')
			alst->f++;
		alst->spaces = *(alst->f) != '*' ? ft_atoi(alst->f) :
			va_arg(params, int);
		if (alst->hyphen && alst->hyphen-- && alst->spaces > 0)
			alst->spaces *= -1;
		while (*(alst->f) != '.' && *(alst->f) != '\0')
			alst->f++;
	}
	if (*(alst->f) == '.')
	{
		alst->f++;
		alst->precision = 1;
		if (*(alst->f) == '-' || ft_isdigit(*(alst->f))
				|| *(alst->f) == '*')
		{
			if (*(alst->f) != '*')
				alst->nb_precision = ft_atoi(alst->f);
			else
				alst->nb_precision = va_arg(params, int);
		}
	}
}
