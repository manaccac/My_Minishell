/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:30:17 by manaccac          #+#    #+#             */
/*   Updated: 2020/12/17 14:30:18 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		init_struc(int *quote, int *space)
{
	*quote = 0;
	*space = 0;
}

static void		write_line(char *word, int fd, t_echo *o)
{
	if (((word[o->i] != '"') && word[o->i] != '\'') && \
			(!ft_isspace(word[o->i])))
	{
		write(fd, &word[o->i], 1);
		o->space = 0;
	}
	else if (o->quote != word[o->i] && o->quote)
		write(fd, &word[o->i], 1);
	else if (o->i > 0 && (o->quote != word[o->i] && \
		!o->quote && word[o->i - 1] == '\\'))
		write(fd, &word[o->i], 1);
	else if (word[o->i] == ' ' && o->quote)
		write(fd, &word[o->i], 1);
	else if ((word[o->i] == '"' || word[o->i] == '\'') && o->quote)
		init_struc(&o->quote, &o->space);
	else if ((word[o->i] == '"' || word[o->i] == '\'') && !o->quote)
		o->quote = word[o->i];
	else if (word[o->i] == ' ' && !o->space && !o->quote)
	{
		write(fd, &word[o->i], 1);
		o->space = 1;
	}
}

void			ft_print_word(t_env *env, t_word *word, t_echo *o)
{
	while (word->word[o->i])
	{
		if (ft_check_is_env(env, word, o))
			break ;
		else if (word->word[o->i] == '\\' && (word->word[o->i + 1] == '\'' || \
			word->word[o->i + 1] == '"') && !o->quote)
			o->i++;
		else if (word->word[o->i] == '\\' && !o->quote && \
					word->word[o->i + 1] == ' ')
			o->i += 1;
		else if (word->word[o->i] == '\\' && !o->quote && \
					word->word[o->i + 1] == '\\')
		{
			write(1, &word->word[o->i], 1);
			o->i += 2;
		}
		else if (word->word[o->i] == '\\' && !o->quote)
			o->i++;
		write_line(word->word, 1, o);
		if (word->word[o->i])
			o->i++;
	}
}

void			ft_prepare_line(t_echo *p, t_env *env, t_word *w)
{
	p->quote = 0;
	p->space = 0;
	while (w)
	{
		p->i = 0;
		ft_print_word(env, w, p);
		w = w->next;
	}
	(!p->option) ? write(1, "\n", 1) : 0;
}

int				parse_argument_echo(char *line, int *option)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	if (line[i] == '-' && line[i + 1] == 'n')
	{
		if (!line[i + 2])
		{
			*option = TRUE;
			i += 2;
		}
		while (line[i] && !ft_strncmp(&line[i], "-n ", 3))
		{
			*option = TRUE;
			i += 3;
		}
	}
	else
		i = 0;
	return (i);
}
