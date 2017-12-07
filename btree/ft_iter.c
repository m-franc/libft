/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:48:38 by mfranc            #+#    #+#             */
/*   Updated: 2017/12/07 15:53:41 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_iter_preorder(t_btree *node, void (*f)(t_btree *node))
{
	if (!node)
		return ;
	f(node);
	if (node->left)
		ft_iter_inorder(node->left, f);
	if (node->right)
		ft_iter_inorder(node->right, f);
}

void		ft_iter_inorder(t_btree *node, void (*f)(t_btree *node))
{
	if (!node)
		return ;
	if (node->left)
		ft_iter_inorder(node->left, f);
	f(node);
	if (node->right)
		ft_iter_inorder(node->right, f);
}

void		ft_iter_postorder(t_btree *node, void (*f)(t_btree *node))
{
	if (!node)
		return ;
	if (node->left)
		ft_iter_inorder(node->left, f);
	if (node->right)
		ft_iter_inorder(node->right, f);
	f(node);
}
