/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/17 20:16:51 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_eos(char **s, char *buffpc, int *i)
{
	char	*eos;
	char	*new;
	char	*color;

	if (!(eos = ft_strdup("{eos}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, eos, ft_strlen(eos))))
		return (ft_exit_color(eos));
	if (!(color = ft_strjoin(buffpc, EOS)))
		return (-1);
	*i += ft_strlen(eos);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (-1);
	ft_strdel(&eos);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
