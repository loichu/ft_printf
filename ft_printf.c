/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:55:42 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/06 18:38:00 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg(char c, va_list ap)
{
	if (c == 'c')
		// char
		return (ft_putchar(va_arg(ap, int)));
	if (c == 's')
		// str
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'p')
		// ptr hex
		return (ft_putchar(va_arg(ap, int)));
	if (c == 'd')
		// dec
		return (ft_putnbr(va_arg(ap, int)));
	if (c == 'i')
		// int
		return (ft_putnbr(va_arg(ap, int)));
	if (c == 'u')
		// udec
		return (ft_putunbr(va_arg(ap, int)));
	if (c == 'x')
		// hex lc
		return (ft_putchar(va_arg(ap, int)));
	if (c == 'X')
		// hex uc
		return (ft_putchar(va_arg(ap, int)));
	if (c == '%')
		// litteral %
		return (ft_putchar('%'));
	// ignore
	// return (0);
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
