/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:35:09 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:35:10 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		printf_d(t_listpf *alst, va_list params)
{
	int		nb;
	int		i;
	int		cpt;

	cpt = 0;
	if (alst->f)
		gest_flags_d(alst, params);
	nb = va_arg(params, int);
	alst->str = ft_itoa_base(nb, 10);
	i = ft_strlen(alst->str);
	if (i < alst->nb_precision)
		i = alst->nb_precision;
	else if (alst->precision == -1 && nb == 0)
		i = 0;
	if (nb < 0 && (int)ft_strlen(alst->str) - 1 < alst->nb_precision)
		alst->spaces > 0 ? alst->spaces-- : alst->spaces++;
	return (printf_d2(cpt, i, alst, nb));
}

int		printf_d2(int cpt, int i, t_listpf *alst, int nb)
{
	while (alst->spaces > 0 && alst->spaces-- > i && ++cpt)
		if (alst->zero == 0 || alst->precision)
			write(1, " ", 1);
		else if (!alst->precision)
		{
			if (nb < 0 && !alst->hyphen++)
				write(1, "-", 1);
			write(1, "0", 1);
		}
	if (nb < 0 && !alst->hyphen)
		write(1, "-", 1);
	i = (nb >= 0) ? (int)ft_strlen(alst->str) : (int)ft_strlen(alst->str) - 1;
	while (alst->precision && alst->nb_precision > i++ && ++cpt)
		write(1, "0", 1);
	i = ((int)ft_strlen(alst->str) < alst->nb_precision || (!nb &&
		!alst->nb_precision && alst->precision) ? alst->nb_precision
			: (int)ft_strlen(alst->str));
	if ((alst->precision == -1 && nb) || alst->precision != -1)
		nb < 0 ? write(1, alst->str + 1, (int)ft_strlen(alst->str) - 1) :
			write(1, alst->str, (int)ft_strlen(alst->str));
	while (alst->spaces < 0 && alst->spaces++ < -i && ++cpt)
		write(1, " ", 1);
	return (alst->precision == -1 && !nb) ? cpt : (cpt +
		(int)ft_strlen(alst->str));
}

void	gest_flags_d(t_listpf *al, va_list params)
{
	if (*(al->f) == '-' || ft_isdigit(*(al->f)) || *(al->f) == '*')
	{
		al->zero = (*(al->f) == '0' && al->f++) ? 1 : 0;
		al->hyphen = (*(al->f) == '-' && al->f++) ? 1 : 0;
		while (*(al->f) == '-')
			al->f++;
		al->spaces = *(al->f) == '*' ? va_arg(params, int) : ft_atoi(al->f);
		if (al->hyphen && al->hyphen-- && al->spaces > 0)
			al->spaces *= -1;
		while (*(al->f) != '.' && *(al->f) != '\0')
			al->f++;
	}
	al->has_spaces = al->spaces != 0 ? 1 : 0;
	if (*(al->f++) == '.' && ++al->precision)
	{
		if (*(al->f) == '-' || ft_isdigit(*(al->f))
				|| *(al->f) == '*')
		{
			if (*(al->f) != '*')
				al->nb_precision = ft_atoi(al->f);
			else
				al->nb_precision = va_arg(params, int);
		}
		!al->nb_precision ? al->precision = -1 : 1;
	}
}
