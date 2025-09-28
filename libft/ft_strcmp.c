/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:51:09 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/26 15:51:10 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
}

// #include <stdio.h>
// int	main()
// {
// 	char s1[]="abc";
// 	char s2[]="abcd";

// 	printf("%d",strcmp(s1, s2));
// }