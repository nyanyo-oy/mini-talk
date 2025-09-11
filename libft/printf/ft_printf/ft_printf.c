/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:07:37 by kenakamu          #+#    #+#             */
/*   Updated: 2025/05/11 14:36:18 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prcss_placeholder(va_list ap, char prcss)
{
	if (prcss == '%')
		return (ft_putchar('%'));
	if (prcss == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (prcss == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (prcss == 'p')
		return (ft_put_ptr(va_arg(ap, void *)));
	if (prcss == 'd' || prcss == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (prcss == 'u')
		return (ft_put_un(va_arg(ap, unsigned int)));
	if (prcss == 'x')
		return (ft_put_hex(va_arg(ap, unsigned int), 1));
	if (prcss == 'X')
		return (ft_put_hex(va_arg(ap, unsigned int), 0));
	return (0);
}

int	ft_printf_core(const char *fmt, va_list ap)
{
	int	len;
	int	ret;

	len = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ret = ft_putchar(*fmt);
			if (ret == -1)
				return (-1);
			len = len + ret;
		}
		else if (*fmt == '%' && *(fmt + 1))
		{
			ret = prcss_placeholder(ap, *(++fmt));
			if (ret == -1)
				return (-1);
			len = len + ret;
		}
		fmt++;
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	len = ft_printf_core(fmt, ap);
	va_end(ap);
	return (len);
}
