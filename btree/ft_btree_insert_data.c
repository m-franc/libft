/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:37:33 by mfranc            #+#    #+#             */
/*   Updated: 2017/12/07 18:10:09 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_insert_data(t_btree **root, t_btree *node, int (*cmpf)(void *, void *))
{
	t_btree	*tmp_root;

	tmp_root = *root;
	if (tmp_root->right && cmpf(tmp_root->item, node->item))
		ft_btree_insert_data(&tmp_root->right, node, cmpf);
	else if (tmp_root->left)
		ft_btree_insert_data(&tmp_root->left, node, cmpf);
	else
		ft_btree_insert_data(&tmp_root->left, node, cmpf);
	if (cmpf(tmp_root->item, node->item))
		tmp_root->right = node;
	else
		tmp_root->left = node;
}
