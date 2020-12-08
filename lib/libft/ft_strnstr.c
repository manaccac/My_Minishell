/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:45:32 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:55:11 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;

	if (!haystack)
		return (NULL);
	if (!needle || !*needle)
		return ((char *)haystack);
	while (len && *haystack)
	{
		i = 0;
		if (*haystack == needle[i])
		{
			while (*(haystack + i) == needle[i] && len)
			{
				i++;
				len--;
				if (needle[i] == '\0')
					return ((char *)haystack);
			}
			len += i;
		}
		haystack++;
		len--;
	}
	return (0);
}
