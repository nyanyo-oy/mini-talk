/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:25:16 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/12 13:25:26 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ptrrlen(char **ptrr)
{
	char	**start;

	if (!ptrr)
		return (0);
	start = ptrr;
	while (*ptrr)
		ptrr++;
	return (ptrr - start);
}
