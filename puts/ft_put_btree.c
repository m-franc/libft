/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_btree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:54:49 by mfranc            #+#    #+#             */
/*   Updated: 2017/12/09 18:18:11 by mfranc           ###   ########.fr       */
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

static void			ft_print_margin(int nb_padd)
{
	char			*padds;

	if (!(padds = ft_strnew(nb_padd)))
		return ;
	ft_memset(padds, ' ', nb_padd);
	ft_putstr(padds);
	ft_strdel(&padds);
}

static void			ft_print_btree_prefix(t_btree *node, void (*print)(t_btree *node), int margin, int height)
{
	ft_printf("{cyan}%p{eoc}\n", node->right);
	ft_printf("{cyan}%p{eoc}\n", node->left);
	if (!node)
		return ;
	margin += height;
	if (node->right)
		ft_print_btree_prefix(node->right, print, margin, height);
	ft_print_margin(margin);
	print(node);
	ft_putchar('\n');
	if (node->left)
		ft_print_btree_prefix(node->left, print, margin, height);
	margin -= height;
}

void				ft_put_btree(t_btree *root, int height)
{
	int				margin;

	margin = 0;
	ft_print_btree_prefix(root, print, margin, height);
}
