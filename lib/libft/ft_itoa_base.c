/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:32:43 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:52:57 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_char(int n, int base)
{
	int cpt;

	cpt = 0;
	if (n <= 0)
		cpt++;
	while (n != 0)
	{
		cpt++;
		n /= base;
	}
	return (cpt);
}

static void	putnbr_itoa(char *str, long n, int last_index, int base)
{
	long	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb > (base - 1))
		putnbr_itoa(str, nb / base, last_index - 1, base);
	if (base == 16 && nb % base > 9)
		str[last_index] = HEXA[nb % base - 10];
	else
		str[last_index] = nb % base + '0';
}

char		*ft_itoa_base(int n, int base)
{
	char	*str;
	int		nb_char;

	nb_char = get_nb_char(n, base);
	if (!(str = ft_calloc(nb_char + 1, sizeof(char))))
		return (0);
	if (n < 0)
		str[0] = '-';
	putnbr_itoa(str, n, nb_char - 1, base);
	return (str);
}
