/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:32:44 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:32:45 by jdel-ros         ###   ########lyon.fr   */
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
