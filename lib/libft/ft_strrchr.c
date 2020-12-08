/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:54:58 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:55:29 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *last_char;

	if (!s)
		return (0);
	last_char = 0;
	while (*s)
	{
		if (*s == c)
			last_char = s;
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return ((char *)last_char);
}
