/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 01:44:51 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:55:09 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*str;
	int		len;

	len = n < (int)ft_strlen(s1) ? n : (int)ft_strlen(s1);
	if (!s1)
		return (0);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memcpy(str, s1, len);
	str[len] = '\0';
	return (str);
}
