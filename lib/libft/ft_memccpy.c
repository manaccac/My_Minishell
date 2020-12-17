/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:32:26 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:32:26 by jdel-ros         ###   ########lyon.fr   */
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
