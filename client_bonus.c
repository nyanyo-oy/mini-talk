/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:09:31 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/12 09:02:35 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	wait_for_server_response(unsigned char *c_ptr)
{
	int	timeout_counter;

	timeout_counter = 0;
	while (!g_server_act && timeout_counter < 5000)
	{
		usleep(10);
		timeout_counter++;
	}
	if (!g_server_act)
	{
		write(STDOUT_FILENO, "Error: Server response timeout\n", 32);
		return (-1);
	}
	*c_ptr = *c_ptr >> 1;
	return (0);
}

static int	send_char_bits(pid_t pid, unsigned char c)
{
	size_t	n;
	int		signal;

	n = 8;
	while (n--)
	{
		g_server_act = 0;
		if (!(c & 1))
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		if (kill(pid, signal) == -1)
		{
			write(STDERR_FILENO, "Error: Failed to send signal\n", 30);
			return (-1);
		}
		if (wait_for_server_response(&c) == -1)
			return (-1);
	}
	return (0);
}

int	client(pid_t pid, char *str)
{
	size_t				i;
	struct sigaction	sa;

	setup_sigactoion(&sa, client_task_end_handler);
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	while (str[i])
	{
		if (send_char_bits(pid, str[i]) == -1)
			return (-1);
		i++;
	}
	if (send_char_bits(pid, '\n') == -1)
		return (-1);
	return (0);
}

static int	validate_and_run_client(const char *pid_str, char *content)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (pid_str[i])
	{
		if (ft_isdigit(pid_str[i]) == false)
		{
			write(STDOUT_FILENO, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	pid = (pid_t)ft_atoi(pid_str);
	if (pid <= 0)
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (-1);
	}
	if (client(pid, content) == -1)
		return (-1);
	return (0);
}

int	main(int arc, char **arv)
{
	if (arc == 3)
		return (validate_and_run_client(arv[1], arv[2]));
	else
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (-1);
	}
}
