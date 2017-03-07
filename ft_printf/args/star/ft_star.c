/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:12:45 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/07 23:10:40 by mfranc           ###   ########.fr       */
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
	if (!(star = ft_lstnew(cp_arg, sizeof(arg))))
		return (NULL);
	ft_strdel(&cp_arg);
	return (star);
}

int		verif_dollar_star(t_list **tmp, char *fstr, size_t conv_index)
{
	size_t	i;
	int		number;

	i = -1;
	if (!*tmp)
		return (0);
	while (fstr[++i] && i < conv_index)
	{
		if (fstr[i] == '*')
		{
			number = ft_atoi(fstr + i + 1);
			if (fstr[i + i] == '$')
			{
				if (number <= ft_listcount(*tmp))
					return (1);
			}
		}
	}
	return (0);
}

int		ft_get_star_arg(t_datas *datas, size_t conv_index,
		char *buff, t_list **tmp)
{
	size_t	i;

	i = -1;
	while (buff[++i] != '*' && i < conv_index)
		;
	if (buff[i] != '*')
		return (0);
	if (*tmp)
	{
		while (buff[++i] && i < conv_index)
		{
			if (buff[i] == '*')
			{
				if (verif_dollar_star(tmp, buff + i, conv_index) == 1)
					return (0);
				if (!((*tmp)->next = ft_get_star(datas)))
					return (-1);
				*tmp = (*tmp)->next;
			}
		}
	}
	else
	{	
		if (verif_dollar_star(tmp, buff, conv_index) == 1)
			return (0);
		if (!(*tmp = ft_get_star(datas)))
			return (-1);
		while (buff[++i] && i < conv_index)
		{
			if (buff[i] == '*')	
			{
				if (verif_dollar_star(tmp, buff + i, conv_index) == 1)
					return (0);
				if (!((*tmp)->next = ft_get_star(datas)))
					return (-1);
				*tmp = (*tmp)->next;
			}
		}
	}
	return (1);
}
