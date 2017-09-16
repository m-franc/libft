/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:15:03 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/16 16:25:16 by mfranc           ###   ########.fr       */
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
			return ;
		}
		node = node->next;
	}
	ft_push_back(ctl_list, new);
}
