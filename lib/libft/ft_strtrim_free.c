/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:32:48 by frfrey            #+#    #+#             */
/*   Updated: 2020/06/02 19:43:13 by rpichon          ###   ########lyon.fr   */
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

char		*ft_strtrim_free(char *s1, char const *set)
{
	char	*str;
	int		end;
	int		i;
	char	*begin;

	if (!s1 || !set)
		return (0);
	i = 0;
	end = ft_strlen(s1);
	while ((end > 1) && is_set(s1[end - 1], set))
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
	free(s1);
	return (begin);
}
