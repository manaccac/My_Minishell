/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:32:48 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:32:49 by jdel-ros         ###   ########lyon.fr   */
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
