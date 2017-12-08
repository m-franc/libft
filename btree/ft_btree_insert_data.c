/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:37:33 by mfranc            #+#    #+#             */
/*   Updated: 2017/12/08 18:26:21 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_insert_data(t_btree **root, t_btree *node, t_btree *parent, int (*cmpf)(void *, void *))
{
	t_btree	*tmp_root;

	tmp_root = *root;
	if (!tmp_root)
		*root = node;	
	else if (cmpf(tmp_root->item, node->item))
	{
		if (tmp_root->right)
			ft_btree_insert_data(&tmp_root->right, tmp_root, node, cmpf);
		else
		{
			node->parent = parent;
			tmp_root->right = node;
		}
	}
	else
	{
		if (tmp_root->left)
			ft_btree_insert_data(&tmp_root->left, tmp_root, node, cmpf);
		else
		{
			node->parent = parent;
			tmp_root->left = node;
		}
	}
}
