/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:33:55 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:54:55 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char *str;
	char *str_begin;

	if (s1 && s2)
	{
		if (!(str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (0);
		str_begin = str;
		while (*s1)
		{
			*str = *s1;
			str++;
			s1++;
		}
		while (*s2)
		{
			*str = *s2;
			str++;
			s2++;
		}
		*str = '\0';
		return (str_begin);
	}
	return (0);
}
