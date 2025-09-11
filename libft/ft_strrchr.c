/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:08:10 by kenakamu          #+#    #+#             */
/*   Updated: 2024/12/20 13:46:27 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*r = NULL;

	while (*s)
	{
		if (*s == (char)c)
			r = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)r);
}
