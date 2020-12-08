/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:22:24 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:54:34 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*ptr_src;
	char		*ptr_dst;

	if (dst && src)
	{
		ptr_src = src;
		ptr_dst = dst;
		while (n--)
		{
			*ptr_dst = *ptr_src;
			if ((unsigned char)*ptr_dst == (unsigned char)c)
				return ((void *)++ptr_dst);
			ptr_dst++;
			ptr_src++;
		}
	}
	return (0);
}
