/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_btree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:54:49 by mfranc            #+#    #+#             */
/*   Updated: 2017/12/05 18:32:14 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*static void	ft_put_node(t_btree *iter_tree)
{
	if (iter_tree->color == RB_RED)
		ft_printf("{red}%s{eoc}", iter_tree->item);
	else
		ft_printf("%s", iter_tree->item);
}
*/

void		f(t_btree *node)
{
	if (node->color == RB_RED)
		ft_printf("{red}%s{eoc}", node->item);
	else
		ft_printf("%s", node->item);
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

t_data_node		ft_init_data_node(int height_tree)
{
	t_data_node	data_node;

	data_node.padding = height_tree + 1;
	data_node.width = data_node.padding * height_tree;
	data_node.middle = data_node.width / 2;
	data_node.padding_right = data_node.middle;
	data_node.padding_left = data_node.middle;
	return (data_node);
}

void		ft_put_btree(t_btree *root, int height)
{
	t_data_node	data_node;

	data_node = ft_init_data_node(height);
	ft_iter_inorder(root, f);
}
