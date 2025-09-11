/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:08:07 by kenakamu          #+#    #+#             */
/*   Updated: 2024/12/20 13:43:47 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(little);
	if (needle_len == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (*big && len >= needle_len)
	{
		if (ft_strncmp (big, little, needle_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
