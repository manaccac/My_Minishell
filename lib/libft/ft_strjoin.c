/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:33:39 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:33:40 by jdel-ros         ###   ########lyon.fr   */
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
