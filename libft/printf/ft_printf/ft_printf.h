/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:07:39 by kenakamu          #+#    #+#             */
/*   Updated: 2025/05/11 14:19:17 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *fmt, ...);
int	ft_printf_core(const char *fmt, va_list ap);
int	prss_placeholder(va_list ap, char prosess);

int	ft_putchar(char c);
int	ft_putstr(char *c);
int	ft_put_ptr(void *ptr);
int	ft_putnbr(int n);
int	ft_put_hex(uintptr_t value, int islower);
int	ft_put_ptr(void *ptr);
int	ft_put_un(unsigned int n);

#endif
