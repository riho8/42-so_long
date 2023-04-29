/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:17:25 by rsihmaok          #+#    #+#             */
/*   Updated: 2022/10/07 10:17:25 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t		ft_putchar_fd_2(char c, int fd);
size_t		ft_putnbr_fd_2(long long n, int fd);
long long	ft_putstr_fd_2(char *s, int fd);
size_t		ft_strlen(const char *str);

int			ft_printf(const char *fmt, ...);
void		ft_print_char(char c, int *count);
void		ft_print_string(char *str, int *count);
void		ft_print_int(int n, int *count);
void		ft_print_point(unsigned long long point, int *count);
void		ft_print_uint(unsigned int n, int *count);
void		ft_print_hex(unsigned int n, int *count, int upper_or_lower);
void		ft_convert_base(unsigned long long n, int base, int to_upper,
				int *count);

#endif