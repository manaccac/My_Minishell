/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:08:57 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:53:17 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *new_begin;

	if (lst)
	{
		new_begin = lst;
		while (new_begin->next)
			new_begin = new_begin->next;
		return (new_begin);
	}
	return (0);
}
