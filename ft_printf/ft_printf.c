/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsihmaok <rshimaok@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:19:14 by rsihmaok          #+#    #+#             */
/*   Updated: 2022/10/06 09:19:14 by rsihmaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_detect_conversions(va_list *ap, char conversion, int *count)
{
	if (conversion == 'c')
		ft_print_char(va_arg(*ap, int), count);
	else if (conversion == 's')
		ft_print_string(va_arg(*ap, char *), count);
	else if (conversion == 'p')
		ft_print_point((unsigned long long)va_arg(*ap, void *), count);
	else if (conversion == 'd' || conversion == 'i')
		ft_print_int(va_arg(*ap, int), count);
	else if (conversion == 'u')
		ft_print_uint(va_arg(*ap, unsigned int), count);
	else if (conversion == 'x')
		ft_print_hex(va_arg(*ap, unsigned int), count, 0);
	else if (conversion == 'X')
		ft_print_hex(va_arg(*ap, unsigned int), count, 1);
	else
		*count += ft_putchar_fd_2(conversion, 1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] != '%')
		{
			count += ft_putchar_fd_2(fmt[i], 1);
		}
		else
		{
			i++;
			ft_detect_conversions(&ap, fmt[i], &count);
		}
		i++;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	int len;
// 	int a;

// 	printf("---you---\n");
// 	len = ft_printf("ab[%c][%s][%s][%p][%%]\n", '\0', "ZZZ\t", "", &a);
// 	printf("%d\n", len);
// 	printf("---ans---\n");
// 	len = printf("ab[%c][%s][%s][%p][%%]\n", '\0', "ZZZ\t", "", &a);
// 	printf("%d\n", len);
// 	printf("---you---\n");
// 	len = ft_printf("[%d][%i][%u][%x][%X]\n", -2147483647, 0, -1, 1234, -1234);
// 	printf("%d\n", len);
// 	printf("---ans---\n");
// 	len = printf("[%d][%i][%u][%x][%X]\n", -2147483647, 0, -1, 1234, -1234);
// 	printf("%d\n", len);
// 	printf("---you---\n");
// 	len = ft_printf("[%s][%p]\n", NULL, 0);
// 	printf("%d\n", len);
// 	printf("---ans---\n");
// 	len = printf("[%s][%p]\n", NULL, 0);
// 	printf("%d\n", len);
// 	printf("---you---\n");
// 	len = ft_printf(NULL, NULL, 0);
// 	printf("%d\n", len);
// 	printf("---ans---\n");
// 	len = printf(NULL, NULL, 0);
// 	printf("%d\n", len);
// 	return (0);
// }