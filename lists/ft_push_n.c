/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 19:17:00 by mfranc            #+#    #+#             */
/*   Updated: 2017/11/24 10:14:13 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_push_n(t_ctl_list *ctl_list, t_list *new, int n)
{
	int		i;
	t_list	*node;

	i = 0;
	node = ctl_list->head;
	if (n == 0)
		ft_push_front(ctl_list, new);
	else if (ctl_list->size <= n)
		ft_push_back(ctl_list, new);
	else
	{
		while (node && i != n)
		{
			node = node->next;
			i++;
		}
		ft_push(node, new);
		ctl_list->size++;
	}
}
