/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:15:03 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/15 16:51:51 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_push(t_list *node, t_list *new)
{
	new->prev = node->prev;
	new->prev->next = new;
	new->next = node;
	new->next->prev = new;
}

void	ft_push_at(t_ctl_list *ctl_list, t_list *new, int(*f)(t_list *node, void *op), void *op)
{
	t_list	*node;

	node = ctl_list->head;
	if (!node)
	{
		ft_push_front(ctl_list, new);
		return ;
	}
	while (node)
	{
		if (f(node, op))
		{
			if (!node->next)
				ft_push_back(ctl_list, new);
			else if (!node->prev)
				ft_push_front(ctl_list, new);
			else
				ft_push(node, new);
		}
		node = node->next;	
	}
}
