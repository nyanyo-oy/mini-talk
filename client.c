#include "minitalk.h"

static int send_char_bits(pid_t pid, unsigned char c, int s_len)
{
	size_t	n;
	int	timeout_counter;
	
	n = 8;
	while (n--)
	{
		g_task_end = 0;
		if (!(c & 1))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(STDERR_FILENO, "Error: Failed to send signal\n", 30);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(STDERR_FILENO, "Error: Failed to send signal\n", 30);
				exit(1);
			}
		}
		
		timeout_counter = 0;
		while (!g_task_end && timeout_counter < 5000)
		{
			usleep(10);
			timeout_counter++;
		}
		
		if (!g_task_end)
		{
			write(STDOUT_FILENO,"Error: Server response timeout\n", 32);
                exit(1); 
		}
		c = c >> 1;
		
		if (s_len > 150000)
			usleep(30);//重要 15万30
		else 
			usleep(30 * (s_len / 150000));//重要 15万30
	}
	return (0);
}

int	client(pid_t pid, char *str)
{
	size_t	i;
	int	s_len;
	struct sigaction sa;
	
	setup_sigactoion(&sa, client_task_end_handler);
	sigaction(SIGUSR1, &sa, NULL);
	s_len = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		if (send_char_bits(pid, str[i], s_len) == -1)
			exit(1);
		i++;
	}
	
	if (send_char_bits(pid, '\n', 1) == -1)
		exit (1);
	
	return (0);
}

int	main (int arc, char **arv)
{
	int	j;
	if (arc == 3)
	{
		j = 0;
		while (arv[1][j])
		{
			if (ft_isdigit(arv[1][j]) == FAILURE)
			{
				write(STDOUT_FILENO, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		client((pid_t)ft_atoi(arv[1]), arv[2]);
		return (0);
	}
	else
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (-1);
	}

}