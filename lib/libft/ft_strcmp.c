/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:29:27 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/26 18:18:58 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (s1 && s2)
		while (s1[i] || s2[i])
		{
			if (s1[i] != s2[i])
				return (s1[i] - s2[i]);
			i++;
		}
	return (0);
}