/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:15:29 by rsihmaok          #+#    #+#             */
/*   Updated: 2022/10/07 10:15:29 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_base(unsigned long long n, int base, int to_upper,
		int *count)
{
	unsigned long long	r;

	r = n % base;
	n = n / base;
	if (n > 0)
		ft_convert_base(n, base, to_upper, count);
	if (r <= 9)
		*count += ft_putnbr_fd_2(r, 1);
	else if (r > 9)
	{
		if (to_upper == 1)
			*count += ft_putchar_fd_2('A' + r - 10, 1);
		else
			*count += ft_putchar_fd_2('a' + r - 10, 1);
	}
}
