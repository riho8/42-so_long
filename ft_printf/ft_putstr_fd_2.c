/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:18:21 by rsihmaok          #+#    #+#             */
/*   Updated: 2022/10/07 10:18:21 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_putstr_fd_2(char *s, int fd)
{
	if (!s)
		return (-1);
	if (ft_strlen(s) > SIZE_MAX)
	{
		write(fd, s, SIZE_MAX);
		*s += SIZE_MAX;
	}
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}
