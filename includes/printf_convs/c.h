/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:05:51 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/16 20:51:05 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_H

# define C_H

# include "../ft_printf.h"

typedef struct	s_datas
{
	char		*result;
	va_list		ap;
	t_list		*args;
	t_list		*tmp_args;
	t_list		*stars;
	t_list		*tmp_stars;
	char		*flags;
	int			*tmp_len;
	int			len;
}				t_datas;

char			*ft_get_c_conv(t_datas *datas);
t_list			*ft_get_c_arg(t_datas *datas);

#endif
