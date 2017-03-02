/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:12:45 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/02 12:49:06 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_star(t_datas *datas)
{
	char	*cp_arg;
	int		arg;
	t_list	*star;

	arg = va_arg(datas->ap, int);
	if (!(cp_arg = ft_itoa(arg, 10, BASEUP)))
		return (NULL);
	if (!(star = ft_lstnew(cp_arg, sizeof(cp_arg))))
		return (NULL);
	ft_strdel(&cp_arg);
	return (star);
}

t_list	*ft_get_star_arg(t_datas *datas, size_t conv_index, char *buff)
{
	t_list	*star;
	t_list	*tmp;
	size_t	i;

	i = -1;
	while (buff[++i] != '*' && i < conv_index)
		;
	if (buff[i] != '*')
		return (NULL);
	if (!(star = ft_get_star(datas)))
		exit(-1);
	tmp = star;
	while (buff[++i] && i < conv_index && star)
	{	
		if (buff[i] == '*')
		{
			if (!(star->next = ft_get_star(datas)))
				exit(-1);
			star = star->next;
		}
	}
	return (tmp);
}
