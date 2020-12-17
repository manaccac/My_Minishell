/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:34:11 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:34:12 by jdel-ros         ###   ########lyon.fr   */
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
