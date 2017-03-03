/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:12:45 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/03 12:22:21 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_star(t_datas *datas)
{
	int		*cp_arg;
	int		arg;
	t_list	*star;

	arg = va_arg(datas->ap, int);
	cp_arg = &arg;
	if (!(star = ft_lstnew(cp_arg, sizeof(arg))))
		return (NULL);
	return (star);
}

int		ft_get_star_arg(t_datas *datas, size_t conv_index,
		char *buff, t_list **tmp)
{
	t_list	*star;
	size_t	i;

	i = -1;
	while (buff[++i] != '*' && i < conv_index)
		;
	if (buff[i] != '*')
		return (0);
	if (!(star = ft_get_star(datas)))
		return (-1);
	*tmp = star;
	while (buff[++i] && i < conv_index && star)
	{
		if (buff[i] == '*')
		{
			if (!(star->next = ft_get_star(datas)))
				return (-1);
			star = star->next;
		}
	}
	return (1);
}
