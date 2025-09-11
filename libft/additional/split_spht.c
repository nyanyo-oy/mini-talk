/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_spht.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:13:34 by kenakamu          #+#    #+#             */
/*   Updated: 2025/08/22 14:31:09 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//this function splits str when appear sp&ht and returns it as a split ptrr
#include "../libft.h"

static int	ct_words(char	*str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		words++;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	}
	return (words);
}

static int	ct_letters(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	return (i);
}

static char	*word_dup(char *str, int len)
{
	int		i;
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (len - i)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	fill_words(char **ptrr, char *str)
{
	int	i;
	int	j;
	int	letters;

	i = 0;
	j = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		letters = ct_letters(&str[i]);
		ptrr[j] = word_dup(&str[i], letters);
		if (!ptrr[j])
		{
			free_ptrr(ptrr);
			return (-1);
		}
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		j++;
	}
	return (0);
}

char	**split_spht(char *str)
{
	char	**ptrr;
	int		words;

	words = ct_words(str);
	ptrr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ptrr)
		return (NULL);
	if (fill_words(ptrr, str) == -1)
	{
		free (ptrr);
		return (NULL);
	}
	ptrr[words] = NULL;
	return (ptrr);
}

//#include <stdio.h>
//int	main(int arc, char **arv)
//{
//	char	**ptrr;
//	int	i = 0;
//	if (arc == 2)
//	{
//		ptrr = split_spht(arv[1]);
//		while (ptrr[i] != NULL)
//		{
//			printf("%s\n",ptrr[i++]);
//		}
//	}
//	write(1, "\n", 1);
//}

//this function splits str when appear sp&ht and returns ptrr