/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:12:45 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/08 16:48:28 by mfranc           ###   ########.fr       */
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
	int		number;

	if (!*tmp)
		return (0);
	number = ft_atoi(fstr + 1);
	if (*(fstr + 1 + ft_ilen(number, 10)) == '$')
	{
		if (number <= ft_listcount(*tmp))
			return (1);
	}
	return (0);
}

int		ft_list_exist(t_datas *datas, size_t conv_index,
		char *buff, t_list **tmp)
{
	t_list	*star;
	size_t	i;

	i = -1;
	while (buff[++i] != '*' && i < conv_index)
		;
	if (buff[i] != '*')
		return (0);
	if (verif_dollar_star(tmp, datas->flags + i, conv_index) == 1)
		return (0);
	if (!((*tmp)->next = ft_get_star(datas)))
		return (-1);
	star = (*tmp)->next;
	while (buff[++i] && i < conv_index && star)
	{
		if (buff[i] == '*')
		{
			if (verif_dollar_star(tmp, datas->flags + i, conv_index) == 1)
				return (0);
			if (!(star->next = ft_get_star(datas)))
				return (-1);
			star = star->next;
		}
	}
	return (1);
}

int		ft_list_dont_exist(t_datas *datas, size_t conv_index,
		char *buff, t_list **tmp)
{
	t_list	*star;
	size_t	i;

	i = -1;
	while (buff[++i] != '*' && i < conv_index)
		;
	if (buff[i] != '*')
		return (0);
	if (!(*tmp = ft_get_star(datas)))
		return (-1);
	star = *tmp;
	while (buff[++i] && i < conv_index && star)
	{
		if (buff[i] == '*')
		{
			if (verif_dollar_star(tmp, datas->flags + i, conv_index) == 1)
				return (0);
			if (!(star->next = ft_get_star(datas)))
				return (-1);
			star = star->next;
		}
	}
	return (1);
}

int		ft_get_star_arg(t_datas *datas, size_t conv_index,
		char *buff, t_list **tmp)
{
	if (!*tmp)
	{
		if ((ft_list_dont_exist(datas, conv_index, buff, tmp)) == -1)
			return (-1);
	}
	else
	{
		if ((ft_list_exist(datas, conv_index, buff, tmp)) == -1)
			return (-1);
	}
	return (1);
}
