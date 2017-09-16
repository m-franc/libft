/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 18:54:27 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/16 20:05:18 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push(t_list *node, t_list *new)
{
	new->prev = node->prev;
	new->prev->next = new;
	new->next = node;
	new->next->prev = new;
}
