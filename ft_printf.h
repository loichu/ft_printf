/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:21:54 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/06 15:53:00 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "utils/utils.h"
//# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *c, ...);

#endif
