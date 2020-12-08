/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:40:06 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:54:53 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	if (!s1)
		return (0);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	ft_memcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}
