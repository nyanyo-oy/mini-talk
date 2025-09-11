/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenakamu <kenakamu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:09:31 by kenakamu          #+#    #+#             */
/*   Updated: 2025/09/11 02:01:49 by kenakamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	wait_for_server_response(unsigned char *c_ptr, int s_len)
{
	int		timeout_counter;

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
	if (s_len <= 150000)
		usleep (30);
	else
		usleep (30 * s_len / 150000);
	return (0);
} //still beta

static int	send_char_bits(pid_t pid, unsigned char c, int s_len)
{
	size_t	n;

	n = 8;
	while (n--)
	{
		g_server_act = 0;
		if (!(c & 1))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(STDERR_FILENO, "Error: Failed to send signal\n", 30);
				return (-1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(STDERR_FILENO, "Error: Failed to send signal\n", 30);
				return (-1);
			}
		}
		if (wait_for_server_response(&c, s_len) == -1)
			return (-1);
	}
	return (0);
}

int	client(pid_t pid, char *str)
{
	size_t				i;
	int					s_len;
	struct sigaction	sa;

	setup_sigactoion(&sa, client_task_end_handler);
	sigaction(SIGUSR1, &sa, NULL);
	s_len = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		if (send_char_bits(pid, str[i], s_len) == -1)
		{
			write(STDOUT_FILENO, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	if (send_char_bits(pid, '\n', 1) == -1)
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (-1);
	}
	return (0);
}

static int	validate_and_run_client(const char *pid_str, char *content)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (pid_str[i])
	{
		if (ft_isdigit(pid_str[i]) == FAILURE)
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
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (-1);
	}
	return (0);
}//returnに問題あり

int	main(int arc, char **arv)
{
	int		ret;

	if (arc == 3)
		ret = validate_and_run_client(arv[1], arv[2]);
	else
	{
		write(STDOUT_FILENO, "Error\n", 6);
		ret = -1;
	}
	return (ret);
}
