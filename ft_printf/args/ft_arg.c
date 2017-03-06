/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:01:10 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/06 18:01:41 by mfranc           ###   ########.fr       */
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

t_list	*ft_get_option(t_list *tmp, int stars, int option, t_datas *datas)
{
	t_list	*tmptmp;

	if (stars == 1)
	{
		tmptmp = tmp;
		while (tmptmp->next)
			tmptmp = tmptmp->next;
		if (!(tmptmp->next = g_get_args[option](datas)))
			return (NULL);
		return (tmp);
	}
	else
	{
		if (!(tmp = g_get_args[option](datas)))
			return (NULL);
		return (tmp);
	}
}

t_list	*ft_get_arg(t_datas *datas, char *buff, size_t *ci, t_list **lst)
{
	size_t	conv_index;
	size_t	i;
	char	*flags;
	int		stars;
	t_list	*tmp;

	i = -1;
	conv_index = ft_strspn(buff, FLAGS);
	if (buff[conv_index] == '\0' || !(ft_strchr(CONVS, buff[conv_index])))
		return (NULL);
	if (!(datas->flags = ft_strsub(buff, 0, conv_index)))
		return (NULL);
	if (ft_strchr(datas->flags, '$') && !*lst)
		datas->un_ord = 1;
	if ((stars = ft_get_star_arg(datas, conv_index, buff, &tmp)) == -1)
		return (NULL);
	while (CONVS && CONVS[++i] != buff[conv_index])
		;
	if (CONVS[i] == '%')
		*ci += conv_index + 2;
	return (ft_get_option(tmp, stars, i, datas));
}

t_list	*ft_get_argslist(t_datas *datas, char *buff)
{
	t_list	*tmp;
	t_list	*new;
	size_t	conv_index;
	size_t	i;

	i = -1;
	tmp = NULL;
	while (buff[++i] != '%')
		;
	if (!(tmp = ft_get_arg(datas, buff + (i + 1), &i, &tmp)))
		return (NULL);
	new = tmp;
	while (buff[++i] && tmp)
	{
		conv_index = 0;
		if (buff[i] == '%')
		{
			while (tmp->next)
				tmp = tmp->next;
			if (!(tmp->next = ft_get_arg(datas, buff + (i + 1), &i, &tmp)))
				return (NULL);
			ft_strdel(&(datas->flags));
		}
	}
	return (new);
}
