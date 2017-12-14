/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:37:33 by mfranc            #+#    #+#             */
/*   Updated: 2017/12/14 17:11:47 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_insert_or_next(t_btree **curr, t_btree **next_branch, t_btree *node, t_btree *parent)
{
	if (*next_branch)	
	{
		*curr = *next_branch;
		return (1);
	}
	else
	{
		node->parent = parent;
		*next_branch = node;
		return (0);
	}
}

void		ft_btree_insert_data(t_btree **root, t_btree *node, t_btree *parent, int (*cmpf)(void *, void *))
{
	t_btree	*curr;

	if (!*root)
		*root = node;
	else
	{
		curr = *root;
		while (curr)
		{
			if (cmpf(curr->item, node->item))
			{
				if (!ft_insert_or_next(&curr, &curr->right, node, parent))
					break ;
			}
			else
			{
				if (!ft_insert_or_next(&curr, &curr->left, node, parent))
					break ;
			}
		}
	}
}
