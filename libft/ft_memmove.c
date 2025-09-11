/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:23:43 by kenakamu          #+#    #+#             */
/*   Updated: 2024/12/20 15:13:29 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;

	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	if (src1 < dest1 && dest1 < src1 + n)
	{
		src1 += n;
		dest1 += n;
		while (n--)
		{
			*(--dest1) = *(--src1);
		}
	}
	else
	{
		while (n--)
		{
			*dest1++ = *src1++;
		}
	}
	return (dest);
}
//後ろからコピー
//   45678
//12345