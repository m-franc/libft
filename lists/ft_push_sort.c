/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 19:16:46 by mfranc            #+#    #+#             */
/*   Updated: 2017/11/24 10:14:50 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_sort(t_ctl_list *ctl_list, t_list *new,
		int (*f)(t_list *node, t_list *new))
{
	t_list	*node;

	node = ctl_list->head;
	while (node)
	{
		if (f(node, new))
		{
			if (!node->prev)
				ft_push_front(ctl_list, new);
			else
			{
				ft_push(node, new);
				ctl_list->size++;
			}
			return ;
		}
		node = node->next;
	}
	ft_push_back(ctl_list, new);
}
