/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:11:04 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/16 16:26:00 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"

int		ft_nodecontent_is_lower(t_list *node, void *op)
{
	if (!op)
		return (1);
	if (ft_strcmp(node->content, op) >= 0)
		return (1);
	else
		return (0);
}

int		main(void)
{
	int			ret;
	char		*line;
	t_ctl_list	*ctl_list;
	t_list		*link;
	
	if (!(ctl_list = ft_memalloc(sizeof(t_ctl_list))))
		return (1);
	while ((ret = get_next_line(0, &line)) == 1)
	{
		link = ft_lstnew_nm(line, ft_strlen(line));
		ft_push_at(ctl_list, link, &ft_nodecontent_is_lower, link->prev);
		ctl_list->size++;
	}
	ft_putstr(RED);
	ft_putlist(ctl_list->head);
	ft_putstr(EOC);
//	ft_lstdelone_if(ctl_list, &ft_content_is_equ, "ok");
//	ft_lstdel(&ctl_list->head);
	return (0);
}
