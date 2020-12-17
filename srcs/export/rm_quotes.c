/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:31:56 by manaccac          #+#    #+#             */
/*   Updated: 2020/12/17 14:31:56 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	get_nb_char(char *str, int i, int nb_char)
{
	char	quote;

	quote = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			if (quote == str[i])
				quote = 0;
			else if (quote == 0)
				quote = str[i];
			else
				nb_char++;
		}
		else if (str[i] == '\\' || str[i] == ' ')
			nb_char = quote != 0 ? nb_char + 2 : nb_char + 1;
		else
			nb_char++;
		if (str[i])
			i++;
	}
	return (nb_char);
}

char		*rm_quotes_free(char *str, int nb, char quote, int i)
{
	char	*new;
	int		j;

	j = -1;
	nb = get_nb_char(str, 0, 0);
	if (!(new = malloc((sizeof(char) + 1) * nb)))
		return (NULL);
	while (str[++j])
		if (str[j] == '"' || str[j] == '\'')
			if (quote == str[j])
				quote = 0;
			else if (quote == 0)
				quote = str[j];
			else
				new[i++] = str[j];
		else if (str[j] == '\\' || str[j] == ' ')
			if (quote && (new[i++] = '\\'))
				new[i++] = str[j];
			else
				new[i++] = str[j];
		else
			new[i++] = str[j];
	new[i] = 0;
	free(str);
	return (new);
}
