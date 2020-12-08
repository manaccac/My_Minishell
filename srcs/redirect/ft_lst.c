/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 10:31:15 by frfrey            #+#    #+#             */
/*   Updated: 2020/06/11 10:35:14 by frfrey           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			ft_check_type(char *line)
{
	if (!strncmp(line, ">>", 2))
		return (DOUBLE);
	else if (!strncmp(line, ">", 1))
		return (SIMPLE);
	else if (!strncmp(line, "<", 1))
		return (S_IN);
	else if (!strncmp(line, "|", 1))
		return (PIPE);
	else
		return (NOTHING);
}

static char			*ft_get_redir_remove_quote(char *line)
{
	int		i;

	i = ft_check_next(line);
	return (ft_strtrim_free(ft_strndup(line, i), " \t\n\r\v\f'\""));
}

static char			*ft_get_line(char *line)
{
	int		i;

	i = ft_check_next(line);
	return (ft_strtrim_free(ft_strndup(line, i), " \t\n\r\v\f"));
}

static t_redir		*lst_new_list(char *line)
{
	t_redir	*new;
	int		i;

	i = 0;
	if (!(new = ft_calloc(1, sizeof(t_redir))))
		return (NULL);
	new->type = ft_check_type(&line[i]);
	while (line[i] && (line[i] == '>' || \
		line[i] == '<' || line[i] == '|'))
		i++;
	new->path = ft_get_redir_remove_quote(&line[i]);
	return (new);
}

t_redir				*init_lst_redir(char *str)
{
	int		i;
	t_redir	*new;
	t_redir	*begin;
	t_redir	*last;

	i = 0;
	if (!(begin = lst_new_list(ft_get_line(str + i))))
		return (NULL);
	last = begin;
	i += ft_check_next(&str[i]);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (!(new = lst_new_list(ft_get_line(str + i))))
			return (NULL);
		last->next = new;
		last = new;
		i += ft_check_next(&str[i]);
	}
	return (begin);
}
