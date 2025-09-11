/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kensei <kensei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:08:04 by kenakamu          #+#    #+#             */
/*   Updated: 2024/12/13 00:34:07 by kensei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*s1 != *s2)
			return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
