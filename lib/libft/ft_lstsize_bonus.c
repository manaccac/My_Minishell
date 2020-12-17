/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:32:20 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/12/17 14:32:21 by jdel-ros         ###   ########lyon.fr   */
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
