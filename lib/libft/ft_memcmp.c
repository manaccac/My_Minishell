/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:08:10 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:54:37 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*ptr_s1;
	const char	*ptr_s2;

	ptr_s1 = s1;
	ptr_s2 = s2;
	if (s1 && s2)
		while (n--)
		{
			if ((unsigned char)*ptr_s1 != (unsigned char)*ptr_s2)
				return ((unsigned char)*ptr_s1 - (unsigned char)*ptr_s2);
			else
			{
				ptr_s1++;
				ptr_s2++;
			}
		}
	return (0);
}
