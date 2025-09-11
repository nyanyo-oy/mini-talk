/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 04:42:09 by kensei            #+#    #+#             */
/*   Updated: 2024/12/20 13:46:36 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*head = s1;
	const char	*tail;
	size_t		len;
	char		*res;

	if (!s1 ||!set)
		return (NULL);
	tail = s1 + ft_strlen(s1) - 1;
	while (*head && ft_strchr(set, *head))
		head++;
	while (tail >= head && ft_strchr(set, *tail))
		tail--;
	len = (tail - head) + 1;
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, head, len + 1);
	res[len] = '\0';
	return (res);
}
