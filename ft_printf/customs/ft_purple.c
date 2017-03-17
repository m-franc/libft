/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_purple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/17 19:53:27 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_purple(char **s, char *buffpc, int *i)
{
	char	*purple;
	char	*new;
	char	*color;

	if (!(purple = ft_strdup("{purple}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, purple, ft_strlen(purple))))
		return (ft_exit_color(purple));
	if (!(color = ft_strjoin(buffpc, PURPLE)))
		return (-1);
	*i += ft_strlen(purple);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (-1);
	ft_strdel(&purple);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
