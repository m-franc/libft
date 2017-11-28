/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pusb_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:24:21 by mfranc            #+#    #+#             */
/*   Updated: 2017/11/07 15:15:10 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_back(t_ctl_list *ctl_list, t_list *new_elem)
{
	if (ctl_list->head)
	{
		new_elem->prev = ctl_list->bottom;
		ctl_list->bottom->next = new_elem;
		ctl_list->bottom = new_elem;
	}
	else
	{
		ctl_list->head = new_elem;
		ctl_list->bottom = new_elem;
	}
	ctl_list->size++;
}
