/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:35:25 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:35:25 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			printf_u(t_listpf *alst, va_list params)
{
	int				nb;
	int				i;
	int				cpt;

	cpt = 0;
	if (alst->f)
		gest_flags_d(alst, params);
	nb = va_arg(params, int);
	alst->str = ft_itoa_base_u(nb, 10);
	i = ft_strlen(alst->str);
	if (i < alst->nb_precision)
		i = alst->nb_precision;
	else if (alst->precision == -1 && nb == 0)
		i = 0;
	return (printf_u2(cpt, i, alst, nb));
}

int			printf_u2(int cpt, int i, t_listpf *alst, int nb)
{
	while (alst->spaces > 0 && alst->spaces-- > i && ++cpt)
		if (alst->zero == 0 || alst->precision)
			write(1, " ", 1);
		else if (!alst->precision)
			write(1, "0", 1);
	i = ft_strlen(alst->str);
	while (alst->precision && alst->nb_precision > i++ && ++cpt)
		write(1, "0", 1);
	i = ((int)ft_strlen(alst->str) < alst->nb_precision || (!nb &&
		!alst->nb_precision && alst->precision) ? alst->nb_precision
			: (int)ft_strlen(alst->str));
	if ((alst->precision == -1 && nb) || alst->precision != -1)
		write(1, alst->str, (int)ft_strlen(alst->str));
	while (alst->spaces < 0 && alst->spaces++ < -i && ++cpt)
		write(1, " ", 1);
	return (alst->precision == -1 && !nb) ? cpt : (cpt +
	(int)ft_strlen(alst->str));
}

static void	putnbr_itoa(char *str, unsigned n, int last_index, int base)
{
	if (n > (unsigned int)(base - 1))
		putnbr_itoa(str, n / base, last_index - 1, base);
	str[last_index] = n % base + '0';
}

char		*ft_itoa_base_u(unsigned int n, int base)
{
	char			*str;
	int				nb_char;
	unsigned int	nb;

	nb = n;
	nb_char = (!nb) ? 1 : 0;
	while (nb != 0)
	{
		nb_char++;
		nb /= base;
	}
	if (!(str = ft_calloc(nb_char + 1, sizeof(char))))
		return (0);
	putnbr_itoa(str, n, nb_char - 1, base);
	return (str);
}
