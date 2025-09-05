#include <stdio.h>
#include <unistd.h>
#include "libft-42/libft.h"
#include <signal.h>

#define SUCSSES 1
#define FAILURE 0

volatile sig_atomic_t g_task_end = 0;

static void	setup_sigactoion(struct sigaction *sa, void (*handler)(int, siginfo_t *, void *))
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
		g_task_end = 1;
	}
}

void signal_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char c;
	static int	bit_counter = 0;
	
	(void)context;
	// client_pid = info->si_pid;

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


int server()
{
	pid_t	pid;
	struct sigaction sa;
	pid =  getpid();
	printf("Server PID: %d\n", pid);
	
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL); //bit0
	sigaction(SIGUSR2, &sa, NULL); //bit1
	
	while(1)
	{
		pause();
	}	
	return (0);
}

// if (s_len <= 150000)
// 	dynamic_delay = 30
// else 
// 	dynamic_delay = 30 * (s_len / 150000)
	


static int send_char_bits(pid_t pid, unsigned char c)
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
		usleep(30);//重要 15万30
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
		if (send_char_bits(pid, str[i]) == -1)
			exit(1);
		i++;
	}
	
	if (send_char_bits(pid, '\n') == -1)
		exit (1);
	
	return (0);
}

int	main (int arc, char **arv)
{
	int	j;
	if (arc == 2 && arv[1][0] == 's' && arv[1][1] == '\0')
	{
		server();
		return (0);
	}
	else if (arc == 4 && arv[1][0] == 'c' && arv[1][1] == '\0')
	{
		j = 0;
		while (arv[2][j])
		{
			if (ft_isdigit(arv[2][j]) == FAILURE)
			{
				write(STDOUT_FILENO, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		client((pid_t)ft_atoi(arv[2]), arv[3]);
		return (0);
	}
	else
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (-1);
	}

}