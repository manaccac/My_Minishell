/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:23:54 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:53:04 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstdel(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
		lst = NULL;
	}
}

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new;
	t_list	*prev;

	if (lst && del)
	{
		new = *lst;
		while (new->next)
		{
			prev = new;
			new = new->next;
			ft_lstdel(prev, del);
		}
		ft_lstdel(new, del);
		*lst = NULL;
	}
}
