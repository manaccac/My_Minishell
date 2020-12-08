/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:35:05 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/25 17:52:22 by frfrey           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list		params;
	t_listpf	*lst;
	int			nb_elem;
	int			nb_char;
	int			tmp;

	nb_char = 0;
	lst = NULL;
	va_start(params, format);
	nb_elem = parse_format(&lst, (char *)format);
	if (nb_elem)
		while (nb_elem--)
		{
			tmp = ft_putstr_len_pf((char *)format);
			nb_char += tmp;
			format += tmp + lst->size;
			nb_char += ft_disp_elem(&lst, params);
		}
	nb_char += ft_putstr_len_pf((char *)format);
	va_end(params);
	return (nb_char);
}
