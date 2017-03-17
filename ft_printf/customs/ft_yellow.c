/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yellow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/17 19:51:20 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_yellow(char **s, char *buffpc, int *i)
{
	char	*yellow;
	char	*new;
	char	*color;

	if (!(yellow = ft_strdup("{yellow}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, yellow, ft_strlen(yellow))))
		return (ft_exit_color(yellow));
	if (!(color = ft_strjoin(buffpc, YELLOW)))
		return (-1);
	*i += ft_strlen(yellow);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (-1);
	ft_strdel(&yellow);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
