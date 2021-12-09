/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 03:04:05 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/06 18:03:54 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// #include <stdio.h>

void	ftu_print(unsigned int n)
{
	char	dgt;

	dgt = 48 + n;
	write(1, &dgt, 1);
}

unsigned int	*ftu_nbdigits(unsigned int n)
{
	static unsigned int	dgts[2];

	if (n > 1000000000)
	{
		dgts[0] = 10;
		dgts[1] = 1000000000;
		return (dgts);
	}
	dgts[0] = 0;
	dgts[1] = 1;
	while (1)
	{
		dgts[0]++;
		if (!(n / (dgts[1] * 10)))
			return (dgts);
		dgts[1] *= 10;
	}
}


int	ft_putunbr(unsigned int n)
{
	unsigned int	*dgts;
	unsigned int	tmp;

	dgts = ftu_nbdigits(n);
	while (dgts[1])
	{
		tmp = n / dgts[1];
		ftu_print(tmp);
		n -= tmp * dgts[1];
		dgts[1] /= 10;
	}
	return (dgts[0]);
}

/* int	main(void)
{
	int	test;

	test = 1000;
	printf("%d: %d %d\n", test, ft_nbdigits(test)[0], ft_nbdigits(test)[1]);
	printf(" %d\n\n", ft_putnbr(test));
	test = -2147483648;
	printf("%d: %d %d\n", test, ft_nbdigits(test)[0], ft_nbdigits(test)[1]);
	printf(" %d\n\n", ft_putnbr(test));
	test = 2147483647;
	printf("%d: %d %d\n", test, ft_nbdigits(test)[0], ft_nbdigits(test)[1]);
	printf(" %d\n\n", ft_putnbr(test));
	test = -1000;
	printf("%d: %d %d\n", test, ft_nbdigits(test)[0], ft_nbdigits(test)[1]);
	printf(" %d\n\n", ft_putnbr(test));
	test = 0;
	printf("%d: %d %d\n", test, ft_nbdigits(test)[0], ft_nbdigits(test)[1]);
	printf(" %d\n\n", ft_putnbr(test));
	test = 8;
	printf("%d: %d %d\n", test, ft_nbdigits(test)[0], ft_nbdigits(test)[1]);
	printf(" %d\n\n", ft_putnbr(test));
	test = -4;
	printf("%d: %d %d\n", test, ft_nbdigits(test)[0], ft_nbdigits(test)[1]);
	printf(" %d\n\n", ft_putnbr(test));
	test = 32;
	printf("%d: %d %d\n", test, ft_nbdigits(test)[0], ft_nbdigits(test)[1]);
	printf(" %d\n\n", ft_putnbr(test));
	test = -43532;
	printf("%d: %d %d\n", test, ft_nbdigits(test)[0], ft_nbdigits(test)[1]);
	printf(" %d\n\n", ft_putnbr(test));
} */
