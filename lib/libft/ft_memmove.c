/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:41:59 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:54:40 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, int len)
{
	char		*ptr_dst;
	const char	*ptr_src;

	ptr_dst = dst;
	ptr_src = src;
	if (!dst && !src)
		return (NULL);
	if (ptr_dst <= ptr_src)
		while (len--)
			*ptr_dst++ = *ptr_src++;
	else
		while (len--)
			*(ptr_dst + len) = *(ptr_src + len);
	return (dst);
}
