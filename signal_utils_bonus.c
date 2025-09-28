/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:09:42 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/28 22:23:21 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_server_act = 0;

void	setup_sigaction(struct sigaction *sa,
		void (*handler)(int, siginfo_t *, void *))
{
	sa->sa_sigaction = handler;
	sa->sa_flags = SA_SIGINFO;
	sigemptyset(&sa->sa_mask);
}

void	client_task_end_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR1)
	{
		g_server_act = 1;
	}
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit_counter = 0;

	(void)context;
	if (signum == SIGUSR1)
	{
		c = c >> 1;
	}
	else if (signum == SIGUSR2)
	{
		c = (c >> 1) | 0x80;
	}
	bit_counter++;
	if (bit_counter == 8)
	{
		write(1, &c, 1);
		bit_counter = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
