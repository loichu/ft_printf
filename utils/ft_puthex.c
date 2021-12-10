/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:06:01 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/10 17:17:45 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <stdio.h>

char	ft_gethex(int n)
{
	char	hex[16];

	hex[0] = '0';
	hex[1] = '1';
	hex[2] = '2';
	hex[3] = '3';
	hex[4] = '4';
	hex[5] = '5';
	hex[6] = '6';
	hex[7] = '7';
	hex[8] = '8';
	hex[9] = '9';
	hex[10] = 'A';
	hex[11] = 'B';
	hex[12] = 'C';
	hex[13] = 'D';
	hex[14] = 'E';
	hex[15] = 'F';
	return (hex[n]);
}

char	ft_gethexlc(int n)
{
	char	hex[16];

	hex[0] = '0';
	hex[1] = '1';
	hex[2] = '2';
	hex[3] = '3';
	hex[4] = '4';
	hex[5] = '5';
	hex[6] = '6';
	hex[7] = '7';
	hex[8] = '8';
	hex[9] = '9';
	hex[10] = 'a';
	hex[11] = 'b';
	hex[12] = 'c';
	hex[13] = 'd';
	hex[14] = 'e';
	hex[15] = 'f';
	return (hex[n]);
}

int	ft_rechex(unsigned long int n, unsigned int cnt, char uc)
{
	if (n > 0 || cnt == 0)
	{
		cnt = ft_rechex(n / 16, ++cnt, uc);
		if (uc)
			ft_putchar(ft_gethex(n % 16));
		else
			ft_putchar(ft_gethexlc(n % 16));
	}
	return cnt;
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
