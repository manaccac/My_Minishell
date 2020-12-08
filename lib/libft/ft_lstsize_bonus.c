/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpichon <rpichon@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:03:59 by rpichon           #+#    #+#             */
/*   Updated: 2020/02/17 15:54:32 by rpichon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*new_begin;

	if (lst)
	{
		new_begin = lst;
		i = 1;
		while (new_begin->next)
		{
			new_begin = new_begin->next;
			i++;
		}
		return (i);
	}
	return (0);
}
