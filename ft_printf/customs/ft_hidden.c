/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hidden.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/17 20:16:51 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_hidden(char **s, char *buffpc, int *i)
{
	char	*hidden;
	char	*new;
	char	*color;

	if (!(hidden = ft_strdup("{hidden}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, hidden, ft_strlen(hidden))))
		return (ft_exit_color(hidden));
	if (!(color = ft_strjoin(buffpc, HIDDEN)))
		return (-1);
	*i += ft_strlen(hidden);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (-1);
	ft_strdel(&hidden);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
