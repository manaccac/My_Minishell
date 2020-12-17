/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:32:34 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:32:35 by jdel-ros         ###   ########lyon.fr   */
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
