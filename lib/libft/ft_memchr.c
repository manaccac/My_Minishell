/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:56:19 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:54:36 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	size_t			len;
	unsigned char	*src;

	if (!s)
		return (NULL);
	len = 0;
	src = (unsigned char*)s;
	while (src[len])
		len++;
	if ((unsigned char)c == 0 && n > len)
		return (src + len);
	if ((unsigned char)c == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return ((void*)s + i);
		i++;
	}
	return (0);
}
