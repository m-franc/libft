/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:07:10 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/16 20:48:40 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_H

# define B_H

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

char			*ft_get_b_conv(t_datas *datas);
t_list			*ft_get_b_arg(t_datas *datas);

#endif
