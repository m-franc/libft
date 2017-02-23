/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 19:51:01 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/15 13:11:18 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_get_c_arg(t_datas *datas)
{
	int				arg;
	char			*argcvd;
	t_list			*new;

	if (!(arg = va_arg(datas->ap, int)))
		return (NULL);
	if (!(argcvd = ft_straddchar(NULL, arg)))
		return (NULL);
	if (!(new = ft_lstnew(argcvd, ft_strlen(argcvd))))
		return (NULL);
	ft_strdel(&argcvd);
	return (new);
}
