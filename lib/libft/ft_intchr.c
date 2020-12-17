/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:30:41 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:30:43 by jdel-ros         ###   ########lyon.fr   */
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
