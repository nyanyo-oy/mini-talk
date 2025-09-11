/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:36:59 by kenakamu          #+#    #+#             */
/*   Updated: 2024/12/20 13:16:52 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == 0 || size == 0)
	{
		p = malloc(1);
		if (!p)
			return (NULL);
		else
		{
			*(char *)p = 0;
			return (p);
		}
	}
	if (size && SIZE_MAX / size < nmemb)
		return (NULL);
	p = malloc(size * nmemb);
	if (!p)
		return (NULL);
	else
	{
		ft_bzero(p, size * nmemb);
		return (p);
	}
}
