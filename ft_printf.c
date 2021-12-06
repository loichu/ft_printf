/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:55:42 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/06 17:31:25 by lhumbert         ###   ########.fr       */
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
		return (ft_putnbr(va_arg(ap, unsigned int)));
	if (c == 'x')
		// hex lc
		return (ft_putchar(va_arg(ap, int)));
	if (c == 'X')
		// hex uc
		return (ft_putchar(va_arg(ap, int)));
	if (c == '%')
		// litteral %
		return (ft_putchar(va_arg(ap, int)));
	// litteral
	return (ft_putchar(va_arg(ap, int)));
}

int	ft_vprintf(const char *c, va_list ap)
{
	size_t	i;

	i = 0;
	while (*c)
	{
		write(1, c, 1);
		if (*c == '%')
			i += print_arg(*(++c), ap);
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
