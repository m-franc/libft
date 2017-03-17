/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:26:59 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/17 12:48:12 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H

# define COLOR_H

# define CSTMLIST "{back},{red},{green},{yellow},{blue},{purple},{cyan},{grey},{default}"

# define CODECSTM "\033[1;30m,\033[1;31m,\033[1;32m,\033[1;33m,\033[1;34m,\033[1;35m,\033[1;36m,\033[1;37m,\033[0;m"

# define BLACK    "\033[1;30m"
# define RED      "\033[1;31m"
# define GREEN    "\033[1;32m"
# define YELLOW   "\033[1;33m"
# define BLUE     "\033[1;34m"
# define PURPLE   "\033[1;35m"
# define CYAN     "\033[1;36m"
# define GREY     "\033[1;37m"
# define DEFAULT  "\033[0;m"

#endif
