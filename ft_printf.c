/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:55:42 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/15 14:03:22 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	if (c == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg(ap, int)));
	if (c == 'x')
		return (ft_puthex(va_arg(ap, int), 0));
	if (c == 'X')
		return (ft_puthex(va_arg(ap, int), 1));
	if (c == '%')
		return (ft_putchar('%'));
	return (ft_putchar(c));
}

int	ft_vprintf(const char *c, va_list ap)
{
	int	i;

	i = 0;
	while (*c)
	{
		if (*c == '%')
			i += print_arg(*(++c), ap);
		else
			i += ft_putchar(*c);
		c++;
	}
	return (i);
}

int	ft_printf(const char *c, ...)
{
	va_list	ap;
	int		r;

	va_start(ap, c);
	r = ft_vprintf(c, ap);
	va_end(ap);
	return (r);
}
