/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:06:01 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/09 20:41:48 by lhumbert         ###   ########.fr       */
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

int	ft_puthex(int n)
{
	int	cnt;

	cnt++;
	if (n > 0 || cnt == 0)
		ft_puthex(n / 16);
	ft_putchar(ft_gethex(n % 16));
	return cnt;
}

int	main(void)
{
	int	test;

	test = 16;
	printf("%d: %d\n\n", test, ft_puthex(test));
	test = 56;
	printf("%d: %d\n\n", test, ft_puthex(test));
	test = -2147483648;
	printf("%d:  %d\n\n", test, ft_puthex(test));
	test = 2147483647;
	printf("%d:  %d\n\n", test, ft_puthex(test));
	test = -1000;
	printf("%d:  %d\n\n", test, ft_puthex(test));
	test = 0;
	printf("%d:  %d\n\n", test, ft_puthex(test));
	test = 8;
	printf("%d:  %d\n\n", test, ft_puthex(test));
	test = -4;
	printf("%d:  %d\n\n", test, ft_puthex(test));
	test = 32;
	printf("%d:  %d\n\n", test, ft_puthex(test));
	test = -43532;
	printf("%d:  %d\n\n", test, ft_puthex(test));
}
