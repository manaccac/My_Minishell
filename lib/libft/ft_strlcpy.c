/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:33:46 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:33:47 by jdel-ros         ###   ########lyon.fr   */
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
