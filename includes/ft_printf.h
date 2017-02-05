/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:38:16 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/05 20:06:42 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include 		<stdarg.h>
# include 		"libft.h"

# define CONVS 	"sSpdDioOuUxXcCbrkeEfFgGaAn"
# define MODIFS "hlhhlljz"
# define FLAGS 	"#0-+*$L."

typedef struct	s_tools
{
	char		*result;
	int			len;
}				t_tools;

int				ft_printf(const char *buff, ...);
char			*ft_fill_buff(t_tools *tools, const char *buff, va_list *ap);

#endif
