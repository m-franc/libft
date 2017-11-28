/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 21:09:45 by mfranc            #+#    #+#             */
/*   Updated: 2017/11/27 11:23:07 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if (!(tmp = malloc(sizeof(*tmp))))
		return (NULL);
	if (!(content))
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		if (!(tmp->content = ft_memalloc(sizeof(*content) * content_size)))
			return (NULL);
		tmp->content = ft_memcpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
	}
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_list	*ft_lstnew_nm(void const *content, size_t content_size)
{
	t_list	*tmp;

	if (!(tmp = ft_memalloc(sizeof(*tmp))))
		return (NULL);
	if (!(content))
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		tmp->content = (void*)content;
		tmp->content_size = content_size;
	}
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}
