/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 15:26:05 by juan              #+#    #+#             */
/*   Updated: 2020/05/19 15:26:28 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_intchr(const char *s, int c, int i)
{
	int len;

	len = ft_strlen(s);
	if (!(s))
		return (0);
	if (c == '\0')
		return (len);
	while (s[i] && s[i] != c)
		i++;
	if (i == len)
		return (len);
	else
		return (i);
}
