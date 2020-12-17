/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:31:34 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:31:35 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_char(int n)
{
	int cpt;

	cpt = 0;
	if (n <= 0)
		cpt++;
	while (n != 0)
	{
		cpt++;
		n /= 10;
	}
	return (cpt);
}

static void	putnbr_itoa(char *str, long n, int last_index)
{
	long nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb > 9)
		putnbr_itoa(str, nb / 10, last_index - 1);
	str[last_index] = nb % 10 + '0';
}

char		*ft_itoa(int n)
{
	char	*str;
	int		nb_char;

	nb_char = get_nb_char(n);
	if (!(str = ft_calloc(nb_char + 1, sizeof(char))))
		return (0);
	if (n < 0)
		str[0] = '-';
	putnbr_itoa(str, n, nb_char - 1);
	return (str);
}
