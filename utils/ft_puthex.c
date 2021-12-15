/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:06:01 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/15 14:04:07 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <stdio.h>

char	ft_gethex(int n, char uc)
{
	char	*hex;

	if (uc)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	return (hex[n]);
}

int	ft_rechex(unsigned long int n, unsigned int cnt, char uc)
{
	if (n > 0 || cnt == 0)
	{
		cnt = ft_rechex(n / 16, ++cnt, uc);
		ft_putchar(ft_gethex(n % 16, uc));
	}
	return (cnt);
}

int	ft_puthex(unsigned int n, char uc)
{
	return (ft_rechex(n, 0, uc));
}

int	ft_putptr(void *ptr)
{
	ft_putstr("0x");
	return (2 + ft_rechex((unsigned long int)ptr, 0, 0));
}

//void	test(int n)
//{
//	static int	testnb;
//	static char	uc;
//
//	printf("TEST #%d: %d\n", testnb, n);
//	if (uc)
//		printf("printf: %X\n", n);
//	else
//		printf("printf: %x\n", n);
//	testnb++;
//	printf("\nreturn: %d\n\n", ft_puthex(n, uc));
//	uc = !uc;
//}
//
//int	main(void)
//{
//	test(5);
//	test(-5);
//	test(15);
//	test(16);
//	test(56);
//	test(-2147483648);
//	test(2147483647);
//	test(-1000);
//	test(0);
//	test(8);
//	test(-4);
//	test(32);
//	test(-43532);
//}
