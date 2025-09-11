/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:57:07 by kenakamu          #+#    #+#             */
/*   Updated: 2024/12/20 13:29:28 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	cpy_len;

	slen = ft_strlen(src);
	if (size == 0)
		return (slen);
	dlen = ft_strlen(dst);
	if (dlen >= size)
		return (size + slen);
	cpy_len = size - dlen - 1;
	if (cpy_len > 0)
		ft_strlcpy (dst + dlen, src, cpy_len + 1);
	return (dlen + slen);
}
