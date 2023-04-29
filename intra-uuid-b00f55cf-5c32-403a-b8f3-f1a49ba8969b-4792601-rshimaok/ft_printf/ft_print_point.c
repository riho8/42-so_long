/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:16:57 by rsihmaok          #+#    #+#             */
/*   Updated: 2022/10/07 10:16:57 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_point(unsigned long long point, int *count)
{
	*count += ft_putstr_fd_2("0x", 1);
	ft_convert_base(point, 16, 0, count);
}
