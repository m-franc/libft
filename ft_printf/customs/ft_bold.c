/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bold.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/17 20:16:51 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_bold(char **s, char *buffpc, int *i)
{
	char	*bold;
	char	*new;
	char	*color;

	if (!(bold = ft_strdup("{bold}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, bold, ft_strlen(bold))))
		return (ft_exit_color(bold));
	if (!(color = ft_strjoin(buffpc, BOLD)))
		return (-1);
	*i += ft_strlen(bold);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (-1);
	ft_strdel(&bold);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
