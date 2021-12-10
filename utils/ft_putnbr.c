/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 03:04:05 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/06 17:12:57 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

//#include <stdio.h>

int	ft_minint()
{
	write(1, "-2147483648", 11);
	return (11);
}

int	ft_putnbrrec(unsigned int n, int cnt)
{
	if (n > 0 || cnt == 0)
	{
		cnt = ft_putnbrrec(n / 10, ++cnt);
		ft_putchar(48 + n % 10);
	}
	return (cnt);
}

int	ft_putnbr(int n)
{
	if (n >= 0)
		return (ft_putnbrrec(n, 0));
	else if (n == -2147483648)
		return (ft_minint());
	ft_putchar('-');
	n *= -1;
	return (ft_putnbrrec(n, 1));
}

int	ft_putunbr(unsigned int n)
{
	return (ft_putnbrrec(n, 0));
}

//int	main(void)
//{
//	int	test;
//
//	test = 1000;
//	printf(" %d\n\n", ft_putnbr(test));
//	test = -2147483648;
//	printf(" %d\n\n", ft_putnbr(test));
//	test = 2147483647;
//	printf(" %d\n\n", ft_putnbr(test));
//	test = -1000;
//	printf(" %d\n\n", ft_putnbr(test));
//	test = 0;
//	printf(" %d\n\n", ft_putnbr(test));
//	test = 8;
//	printf(" %d\n\n", ft_putnbr(test));
//	test = -4;
//	printf(" %d\n\n", ft_putnbr(test));
//	test = 32;
//	printf(" %d\n\n", ft_putnbr(test));
//	test = -43532;
//	printf(" %d\n\n", ft_putnbr(test));
//}
