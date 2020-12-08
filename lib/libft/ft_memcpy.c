/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:54:22 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:54:38 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ptr_dst;
	const char	*ptr_src;

	if (dst)
	{
		ptr_dst = dst;
		ptr_src = src;
		if (src || dst)
			while (n--)
				*ptr_dst++ = *ptr_src++;
		return (dst);
	}
	return (NULL);
}
