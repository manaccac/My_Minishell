/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:31:48 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:31:49 by jdel-ros         ###   ########lyon.fr   */
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
