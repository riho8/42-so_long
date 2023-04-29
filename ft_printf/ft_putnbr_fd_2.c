/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:18:13 by rsihmaok          #+#    #+#             */
/*   Updated: 2022/10/07 10:18:13 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_putnbr_count(long long nb, size_t *count)
{
	size_t	digit;

	digit = 1;
	while (nb > 9)
	{
		nb /= 10;
		digit *= 10;
		*count += 1;
	}
	return (digit);
}

size_t	ft_putnbr_fd_2(long long n, int fd)
{
	size_t		digit;
	long long	nb;
	size_t		count;

	count = 1;
	if (n < 0)
	{
		count += ft_putchar_fd_2('-', fd);
		nb = -n;
	}
	else
		nb = n;
	digit = ft_putnbr_count(nb, &count);
	while (digit > 0)
	{
		ft_putchar_fd_2((nb / digit % 10) + '0', fd);
		digit /= 10;
	}
	return (count);
}

// int main(void){
// 	ft_putnbr_fd_2(0,1);
// 	printf("\n");
// 	ft_putnbr_fd_2(100,1);
// 	printf("\n");
// 	ft_putnbr_fd_2(-1234,1);
// 	printf("\n");
// 	ft_putnbr_fd_2(-2147483648,1);
// 	printf("\n");
// 	ft_putnbr_fd_2(2147483647,1);
// 	printf("\n");
// 	ft_putnbr_fd_2(-2147483648000,1);
// 	printf("\n");

// 	return (0);
// }