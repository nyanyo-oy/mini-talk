/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 07:10:42 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/14 01:01:34 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int	getlen(char const *s, char c)
{
	char const	*s0 = s;

	while (*s && *s != c)
		s++;
	return (s - s0);
}

static char	**free_return(char **p, int i)
{
	int	love;

	love = 0;
	while (love < i)
	{
		free(p[love]);
		love++;
	}
	free(p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		j;
	size_t	word_len;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	p = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (i < count_words(s, c))
	{
		while (s[j] == c)
			j++;
		word_len = getlen(&s[j], c);
		p[i] = ft_substr(s, j, word_len);
		if (!p[i])
			return (free_return(p, i));
		j += word_len;
		i++;
	}
	p[i] = NULL;
	return (p);
}

// #include <stdio.h>
// int	main(int arc, char **arv)
// {
// 	char	**ptrr;
// 	int	i = 0;
// 	if (arc == 2)
// 	{
// 		ptrr = ft_split(arv[1], ' ');
// 		while (ptrr[i] != NULL)
// 		{
// 			printf("%s\n",ptrr[i++]);
// 		}
// 	}
// 	write(1, "\n", 1);
// }