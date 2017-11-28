/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:12:00 by mfranc            #+#    #+#             */
/*   Updated: 2017/11/24 10:13:49 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_front(t_ctl_list *ctl_list, t_list *new)
{
	if (ctl_list->head)
	{
		new->next = ctl_list->head;
		new->next->prev = new;
		ctl_list->head = new;
	}
	else
	{
		ctl_list->head = new;
		ctl_list->bottom = new;
	}
	ctl_list->size++;
}
