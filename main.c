#include <stdio.h>
#include <unistd.h>
#include "libft-42/libft.h"
#include <signal.h>

#define SUCSSES 1
#define FAILURE 0

void signal_handler(int signum)
{
	static unsigned char c;
	static int	bit_counter = 0;

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
}	

int server()
{
	pid_t	pid;
	struct sigaction sa;
	pid =  getpid();
	printf("Server PID: %d\n", pid);
	
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL); //bit0
	sigaction(SIGUSR2, &sa, NULL); //bit1
	while(1){
		pause();
		// 何かでcからの情報を待ち受けて→うけとったら
		// 情報を加工してコンソールに表示
	}	
	return (0);
}

int	client(pid_t pid, char *str)
{
	size_t	i;
	size_t	n;
	unsigned char	c;
	
	i = 0;
	while (str[i])
	{
		c = str[i];
		n = 8;
		while (n--)
		{
			if (!(c & 1))
			{
				if (kill(pid, SIGUSR1) == -1)
					
			}
			else
			{
				kill(pid, SIGUSR2);
			}
			c = c >> 1;
			usleep(100);
		}
		i++;
	}
	// kill(pid, SIGUSR3);
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