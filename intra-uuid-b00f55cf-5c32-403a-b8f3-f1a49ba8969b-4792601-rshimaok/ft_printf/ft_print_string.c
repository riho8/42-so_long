/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:17:01 by rsihmaok          #+#    #+#             */
/*   Updated: 2022/10/07 10:17:01 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(char *str, int *count)
{
	long long	len;

	len = ft_putstr_fd_2(str, 1);
	if (len == -1)
		*count += ft_putstr_fd_2("(null)", 1);
	else
		*count += len;
}
