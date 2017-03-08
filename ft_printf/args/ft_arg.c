/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:01:10 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/08 12:30:21 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_get_args	g_get_args[] =
{
	ft_get_s_arg, ft_get_ls_arg, ft_get_p_arg, ft_get_d_arg,
	ft_get_ld_arg, ft_get_d_arg, ft_get_o_arg, ft_get_lo_arg,
	ft_get_u_arg, ft_get_lu_arg, ft_get_x_arg, ft_get_lx_arg,
	ft_get_c_arg, ft_get_lc_arg, ft_get_b_arg, ft_get_n_arg,
	ft_get_percent_arg,
};

int		ft_get_option(t_list **tmp, int stars, int option, t_datas *datas)
{
	t_list	*tmptmp;

	if (*tmp)
	{
		tmptmp = *tmp;
		while (tmptmp->next)
			tmptmp = tmptmp->next;
		if (!(tmptmp->next = g_get_args[option](datas)))
			return (-1);	
//		PSTR("ON A NOTRE CONV : ")
//		ft_putendl(tmptmp->next->content);
	}
	else
	{
		if (!(*tmp = g_get_args[option](datas)))
			return (-1);
	}
	return (1);
}

int		verif_dollar(t_list **tmp, char *fstr)
{
	size_t	i;
	int		number;

	i = -1;
	if (!*tmp)
		return (0);
	while (fstr[++i])
	{
		if (ft_isdigit(fstr[i]))
		{
			number = ft_atoi(fstr + i);
			if (fstr[i + ft_ilen(number, 10)] == '$')
			{
				if (number <= ft_listcount(*tmp))
					return (1);
			}
		}
	}
	return (0);
}

int		ft_get_arg(t_datas *datas, char *buff, size_t *ci, t_list **lst)
{
	size_t	conv_index;
	size_t	i;
	char	*flags;
	int		stars;

	i = -1;
	conv_index = ft_strspn(buff, FLAGS);
	if (buff[conv_index] == '\0' || !(ft_strchr(CONVS, buff[conv_index])))
		return (-1);
	if (!(datas->flags = ft_strsub(buff, 0, conv_index)))
		return (-1);
	if (ft_strchr(datas->flags, '$') && !*lst)
		datas->un_ord = 1;
	if (verif_dollar(lst, datas->flags) == 1 && datas->un_ord == 1)
		return (0);
	if ((stars = ft_get_star_arg(datas, conv_index, buff, lst)) == -1)
		return (-1);
	while (CONVS && CONVS[++i] != buff[conv_index])
		;
	if (CONVS[i] == '%')
		*ci += conv_index + 2;
	if (ft_get_option(lst, stars, i, datas) == -1)
		return (-1);
	return (1);
}

t_list	*ft_get_argslist(t_datas *datas, char *buff)
{
	t_list	*tmp;
	t_list	*new;
	size_t	conv_index;
	size_t	i;
	int		argslist;

	i = -1;
	tmp = NULL;
	while (buff[++i] != '%')
		;
	if ((argslist = ft_get_arg(datas, buff + (i + 1), &i, &tmp)) == -1)
		return (NULL);
	new = tmp;
	while (buff[++i] && tmp)
	{
		conv_index = 0;
		if (buff[i] == '%')
		{
			while (tmp->next)
				tmp = tmp->next;
			if ((argslist = ft_get_arg(datas, buff + (i + 1), &i, &tmp)) == -1)
				return (NULL);
			ft_strdel(&(datas->flags));
		}
	}
	return (new);
}
