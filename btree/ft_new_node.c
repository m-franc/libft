/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:36:42 by mfranc            #+#    #+#             */
/*   Updated: 2017/12/01 15:45:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree		*ft_new_node(void const *item)
{
	t_btree	*node;

	if (!(node = malloc(sizeof(*node))))
		return (NULL);
	node->parent = NULL;
	node->right = NULL;
	node->left = NULL;
	node->item = (void*)item;
	node->color = RB_RED;
	return (node);
}
