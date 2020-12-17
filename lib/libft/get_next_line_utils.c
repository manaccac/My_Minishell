/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:34:39 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:34:40 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	j = -1;
	i = -1;
	if (s1 && s2)
	{
		if (!(str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (0);
		while (s1 && s1[++i])
			str[i] = s1[i];
		while (s2[++j])
			str[i++] = s2[j];
		str[i] = '\0';
		free(s1);
		return (str);
	}
	free(s1);
	return (NULL);
}

int		search_eol(char *s1)
{
	int i;

	i = -1;
	while (s1 && s1[++i])
		if (s1[i] == '\n')
			return (i);
	return (-1);
}

char	*ft_strndup_free(char *s1, int size, int to_free)
{
	char	*str;
	int		i;
	int		len;

	len = ft_strlen(s1);
	if (size < len)
		len = size;
	i = -1;
	if (!s1)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[++i] && i < size)
		str[i] = s1[i];
	str[i] = '\0';
	if (to_free)
		free(s1);
	return (str);
}
