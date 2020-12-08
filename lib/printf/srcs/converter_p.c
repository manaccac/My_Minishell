/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:38:36 by rpichon           #+#    #+#             */
/*   Updated: 2020/03/24 13:09:48 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			printf_p(t_listpf *alst, va_list params)
{
	unsigned long long		nb;
	int						i;
	int						cpt;

	cpt = 0;
	if (alst->f)
		gest_flags_d(alst, params);
	nb = (unsigned long long)va_arg(params, void *);
	alst->str = ft_itoa_base_p(nb, "0123456789abcdef");
	i = ft_strlen(alst->str);
	return (printf_p2(cpt, i, alst, nb));
}

int			printf_p2(int cpt, int i, t_listpf *alst, int nb)
{
	while (alst->spaces > 0 && alst->spaces-- - 2 > i && ++cpt)
		write(1, " ", 1);
	write(1, "0x", 2);
	cpt += 2;
	i = ((int)ft_strlen(alst->str) < alst->nb_precision ? alst->nb_precision :
			(int)ft_strlen(alst->str));
	if ((alst->precision == -1 && nb) || alst->precision != -1)
		write(1, alst->str, (int)ft_strlen(alst->str));
	while (alst->spaces < 0 && alst->spaces++ + 2 < -i && ++cpt)
		write(1, " ", 1);
	return (alst->precision == -1 && !nb) ? cpt : (cpt +
		(int)ft_strlen(alst->str));
}

static void	putnbr_itoa(char *str, unsigned long long n, int last, char *base)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (n > (unsigned long long)(len_base - 1))
		putnbr_itoa(str, n / len_base, last - 1, base);
	str[last] = base[n % len_base];
}

char		*ft_itoa_base_p(unsigned long long int n, char *base)
{
	char				*str;
	int					nb_char;
	unsigned long long	nb;

	nb = n;
	nb_char = (!nb) ? 1 : 0;
	while (nb != 0)
	{
		nb_char++;
		nb /= ft_strlen(base);
	}
	if (!(str = ft_calloc(nb_char + 1, sizeof(char))))
		return (0);
	putnbr_itoa(str, n, nb_char - 1, base);
	return (str);
}
