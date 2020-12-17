/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:34:07 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:34:08 by jdel-ros         ###   ########lyon.fr   */
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
