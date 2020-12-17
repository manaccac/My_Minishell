/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:34:43 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:34:43 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(int fd, char **line, char **save)
{
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	int				eol;

	if (!*save)
		*line = ft_strndup_free("", 1, 0);
	else if (*save)
		if (check_static(save, line))
			return (1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*line = ft_strjoin_free(*line, buf);
		if ((eol = search_eol(*line)) >= 0)
		{
			*save = ft_strndup_free((*line) + (eol + 1),
			ft_strlen(*line) - eol, 0);
			*line = ft_strndup_free(*line, eol, 1);
			return (1);
		}
	}
	if (ret == -1)
		return (-1);
	*save = NULL;
	return (0);
}

int		check_static(char **save, char **line)
{
	int		eol;

	if ((eol = search_eol(*save)) >= 0)
	{
		*line = ft_strndup_free(*save, eol, 0);
		if ((*save)[eol + 1] == '\0')
		{
			free(*save);
			*save = NULL;
		}
		else
			ft_memmove(*save, (*save) + eol + 1, ft_strlen(*save) - eol);
		return (TRUE);
	}
	*line = ft_strndup_free(*save, ft_strlen(*save), 1);
	return (FALSE);
}
