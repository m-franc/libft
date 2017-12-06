/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_btree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:54:49 by mfranc            #+#    #+#             */
/*   Updated: 2017/12/06 19:30:58 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void			print(t_btree *node)
{
	if (node->color == RB_RED)
		ft_printf("{red}%s{eoc}", node->item);
	else
		ft_printf("%s", node->item);
}

static t_data_node	ft_init_data_node(int height_tree)
{
	t_data_node		data_node;

	data_node.padding = height_tree + 1;
	data_node.width = data_node.padding * height_tree;
	data_node.middle = data_node.width / 2;
	data_node.margin = data_node.middle;
	return (data_node);
}

static void			ft_print_padding(int nb_padd)
{
	char			*padds;

	if (!(padds = ft_strnew(nb_padd)))
		return ;
	ft_memset(padds, ' ', nb_padd);
	ft_putstr(padds);
	ft_strdel(&padds);
}

static void			ft_print_btree_prefix(t_btree *node, t_data_node *data_node, void (*print)(t_btree *node))
{
	if (!node)
		return ;
	ft_print_padding(data_node->margin);
	print(node);
	data_node->margin -= data_node->padding;
	ft_putchar('\n');
	if (node->left)
		ft_print_btree_prefix(node->left, data_node, print);
	if (node->right)
		ft_print_btree_prefix(node->right, data_node, print);
}

void				ft_put_btree(t_btree *root, int height)
{
	t_data_node		data_node;

	data_node = ft_init_data_node(height);
	ft_print_btree_prefix(root, &data_node, print);
}
