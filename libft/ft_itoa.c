/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:52:41 by kensei            #+#    #+#             */
/*   Updated: 2024/12/20 18:05:01 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static int	isminus(n)
//{
//	if (n < 0)
//		return (1);
//	else
//		return (0);
//}

static int	ft_numlen(int n)
{
	int	numlen;

	if (n < 0)
		n = -n;
	numlen = 1;
	while (n / 10)
	{
		n /= 10;
		numlen++;
	}
	return (numlen);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		numlen;
	int		minus;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	minus = (n < 0);
	if (minus)
		n = -n;
	numlen = minus + ft_numlen(n);
	str = (char *)malloc((numlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[numlen] = '\0';
	while (numlen--)
	{
		str[numlen] = ((n % 10) + '0');
		n /= 10;
	}
	if (minus)
		str[0] = '-';
	return (str);
}

//#include <stdio.h>
//int main(void)
//{
//	int	i;
//	i = 2147483648;
//	printf ("%s\n",ft_itoa(i));
//    return 0;
//}
