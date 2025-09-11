/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ptrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:12:58 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/09 16:13:04 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_ptrr(char **ptrr)
{
	int	i;

	if (!ptrr)
		return ;
	i = 0;
	while (ptrr[i])
		free (ptrr[i++]);
	free(ptrr);
}
