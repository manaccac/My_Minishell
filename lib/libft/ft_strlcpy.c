/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:09:48 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:55:03 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t i;

	if (src && dst)
	{
		i = -1;
		while (++i < n - 1 && src[i] && n)
			dst[i] = src[i];
		if (n > 0)
			dst[i] = '\0';
		return (ft_strlen(src));
	}
	return (0);
}
