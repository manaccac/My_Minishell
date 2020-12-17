/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:33:31 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:33:31 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_f(char *s1)
{
	char	*str;

	if (!s1)
		return (0);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	ft_memcpy(str, s1, ft_strlen(s1) + 1);
	free(s1);
	return (str);
}
