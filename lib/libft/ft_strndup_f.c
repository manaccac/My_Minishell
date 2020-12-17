/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:34:01 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:34:01 by jdel-ros         ###   ########lyon.fr   */
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
