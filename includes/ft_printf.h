/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 20:38:16 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/06 19:06:17 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include 		<stdarg.h>
# include 		"libft.h"

# define CONVS 	"sSpdDioOuUxXcCbrkeEfFgGaAn%"
# define MODIFS "hlhhlljz"
# define FLAGS 	"#0-+*$L."

typedef struct	s_datas
{
	char		*result;
	va_list		args;
	char		*flags;
	int			len;
}				t_datas;

int				ft_printf(const char *buff, ...);
char			*ft_fill_buff(t_datas *datas, char *buff);
char			*ft_get_unconvdatas(t_datas *datas, char *buff, size_t o);
char			*ft_get_flags(t_datas *datas, char *buff);

#endif
