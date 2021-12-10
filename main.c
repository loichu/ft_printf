/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:57:39 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/10 17:18:08 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define NARGS_SEQ(_1,_2,_3,_4,_5,_6,_7,_8,_9,N,...) N
#define NARGS(...) NARGS_SEQ(__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1)

#define test(...) test(NARGS(__VA_ARGS__) - 1, __VA_ARGS__)

int	ft_vprintf(const char *c, va_list ap);

static int	(test)(int n, const char *c, ...)
{
	va_list		ft_ap;
	va_list		ap;
	int			ft_ret;
	int			ret;
	static int	nt;

	nt++;
	printf("TEST #%i\n", nt);
	va_start(ft_ap, c);
	va_start(ap, c);
	printf("%i params received\n", n);
	printf("input: %s\n", c);
	printf("ft_printf:\n");
	ft_ret = ft_vprintf(c, ft_ap);
	printf("\nprintf:\n");
	ret = vprintf(c, ap);
	printf("\nft_ret: %i\tret: %i", ft_ret, ret);
	printf("\n\n");
	va_end(ap);
	va_end(ft_ap);
	return (0);
}

int	main(void)
{
	test("hello %c, %i, %d, %s", 'a', 1, 4.1, "test");
	test("hello %c, %i, %d, %s", 'a', 1, 4, "test");
	test("hello %u, %i, %d", -3, -3, -3);
	test("hello %%, %w, %y");
	test("hello %, %. %$ %)");
	test("%x, %X, %x, %X, %x", -2147483648, 2147483647, 0, -5, 23764);
	test("%p", &test);
	test("%p", NULL);
	test("%p", 0);
	return (0);
}
