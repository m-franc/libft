/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:22:42 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/16 20:41:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR_H

# define STAR_H

# include "../ft_printf.h"

t_list			*ft_get_star_arg(t_datas *datas, size_t conv_index, char *buff);
t_list			*ft_get_star(t_datas *datas);

#endif
