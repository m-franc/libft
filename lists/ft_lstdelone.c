/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 21:24:58 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/16 20:05:14 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_ctl_list *ctl_list, t_list **node)
{
	t_list	*to_free;
	t_list	*next_node;
	t_list	*prev_node;
	
	to_free = *node;
	next_node = (*node)->next;
	prev_node = (*node)->prev;
	if (next_node)
		next_node->prev = prev_node;
	else
		ctl_list->bottom = prev_node;	
	if (prev_node)
		prev_node->next = next_node;
	else
		ctl_list->head = next_node;
	ft_memdel((void**)&to_free);
	*node = next_node;
}
