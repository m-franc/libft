/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:38:16 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/18 21:32:32 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include 		<stdarg.h>
# include 		"libft.h"

# define CONVS 	"sSpdDioOuUxXcCbrkeEfFgGaAn"
# define MODIFS "hhhllljz"
# define FLAGS 	"#0-+*$L."

int				ft_printf(const char *buff, ...);

#endif
