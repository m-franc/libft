/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:08:21 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/16 16:08:41 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERCENT_H

# define PERCENT_H

#include "../ft_printf.h"

char			*ft_get_percent_conv(t_datas *datas);
t_list			*ft_get_percent_arg(t_datas *datas);

#endif
