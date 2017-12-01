/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_btree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:54:49 by mfranc            #+#    #+#             */
/*   Updated: 2017/12/01 18:33:33 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_node(t_btree *node)
{
	if (iter_tree->color == RB_RED)
		ft_printf("{red}%s{eoc}", iter_tree->item);
	else
		ft_printf("%s", iter_tree->item);
}

void		ft_put_btree(t_btree *root, int height)
{
	t_btree	*iter_tree;
	int		i;
	int		middle;
	int		width;
	int		padding;
	int		padding_right;
	int		padding_left;
	char	space;

	space = ' ';
	padding = 4;
	width = padding * height;
	middle = width / 2;
	iter_tree = root;
	i = -1;
	padding_right = middle;
	padding_left = middle;
	while (++i < depth)
	{
		write(1, &space, padding);
		ft_put_node(iter_tree);

	}
}
