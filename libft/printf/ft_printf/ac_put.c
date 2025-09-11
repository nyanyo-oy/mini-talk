/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:49:41 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/14 01:49:42 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		if (ft_putchar(*str) == -1)
			return (-1);
		len++;
		str++;
	}
	return (len);
}

int	ft_put_ptr(void *ptr)
{
	int	len;
	int	hex_len;

	len = 0;
	if (ptr == NULL)
	{
		if (ft_putstr("(nil)") == -1)
			return (-1);
		return (5);
	}
	if (ft_putstr("0x") == -1)
		return (-1);
	len = 2;
	hex_len = ft_put_hex((uintptr_t)ptr, 1);
	if (hex_len == -1)
		return (-1);
	return (len + hex_len);
}

int	ft_putnbr(int n)
{
	int	len;

	if (n == INT_MIN)
		return (ft_putstr("-2147483648"));
	len = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len++;
		n *= -1;
	}
	if (n / 10)
		len += ft_putnbr(n / 10);
	if (ft_putchar('0' + (n % 10)) == -1)
		return (-1);
	len++;
	return (len);
}
