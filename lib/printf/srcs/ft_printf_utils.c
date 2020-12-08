/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrey <frfrey@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:58:34 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/25 17:52:19 by frfrey           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_listpf	*ft_lstnew_addback(t_listpf **alst, char *flags, char type)
{
	t_listpf	*new;
	t_listpf	*begin;

	if (!(new = ft_calloc(1, sizeof(t_listpf))))
		return (NULL);
	if (*flags)
		new->f = ft_strdup(flags);
	new->size = ft_strlen(new->f) + 2;
	new->debut_flags = new->f;
	new->type = type;
	if (!*alst)
		*alst = new;
	else
	{
		begin = ft_lstlast_pf(*alst);
		begin->next = new;
	}
	return (new);
}

void		get_next_lst(t_listpf **alst)
{
	t_listpf	*lst;

	lst = (*alst)->next;
	free((*alst)->f);
	free((*alst)->text);
	free((*alst));
	*alst = lst;
}

t_listpf	*ft_lstlast_pf(t_listpf *lst)
{
	t_listpf	*new_begin;

	if (lst)
	{
		new_begin = lst;
		while (new_begin->next)
			new_begin = new_begin->next;
		return (new_begin);
	}
	return (0);
}

void		lstdel_first(t_listpf **alst)
{
	t_listpf	*lst;

	lst = *alst;
	lst = lst->next;
	if ((*alst)->debut_flags)
		free((*alst)->debut_flags);
	if ((*alst)->str)
		free((*alst)->str);
	if ((*alst)->text)
		free((*alst)->text);
	free(*alst);
	*alst = lst;
}

int			ft_putstr_len_pf(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] && s[i] != '%')
			i++;
		write(1, s, i);
	}
	return (i);
}
