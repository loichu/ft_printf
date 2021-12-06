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

// #include <stdio.h>

int	ft_minint()
{
	write(1, "-2147483648", 11);
	return (11);
}

void	ft_print(int n)
{
	char	dgt;

	dgt = 48 + n;
	write(1, &dgt, 1);
}

int	*ft_nbdigits(int n)
{
	static int	dgts[2];

	if (n > 1000000000 || n < -1000000000)
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


int	ft_putnbr(int n)
{
	int		*dgts;
	int		tmp;

	dgts = ft_nbdigits(n);
	if (n == -2147483648)
		return (ft_minint());
	if (n < 0)
	{
		write(1, "-", 1);
		dgts[0]++;
		n *= -1;
	}
	while (dgts[1])
	{
		tmp = n / dgts[1];
		ft_print(tmp);
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
