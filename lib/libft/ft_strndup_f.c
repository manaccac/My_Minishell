/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 12:02:19 by frfrey            #+#    #+#             */
/*   Updated: 2020/03/23 12:03:00 by frfrey           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup_f(char *s1, int n)
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
	free(s1);
	return (str);
}
