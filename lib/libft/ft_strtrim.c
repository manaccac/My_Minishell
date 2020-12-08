/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:40:24 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:55:14 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
		if (*set == c)
			return (1);
		else
			set++;
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		end;
	int		i;
	char	*begin;

	if (!s1 || !set)
		return (0);
	i = 0;
	end = ft_strlen(s1);
	while (is_set(s1[end - 1], set) && (end > 1))
		end--;
	while (is_set(s1[i], set))
		i++;
	if (i <= end)
		if (!(str = malloc(sizeof(char) * (end - i + 1))))
			return (0);
	if (i > end)
		if (!(str = malloc(1)))
			return (0);
	begin = str;
	while (i < end)
		*str++ = s1[i++];
	*str = '\0';
	return (begin);
}
