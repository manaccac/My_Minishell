/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:32:30 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:32:31 by jdel-ros         ###   ########lyon.fr   */
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
