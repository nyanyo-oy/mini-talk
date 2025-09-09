#include "minitalk.h"


volatile sig_atomic_t g_task_end = 0;

void	setup_sigactoion(struct sigaction *sa, void (*handler)(int, siginfo_t *, void *))
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

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char c;
	static int	bit_counter = 0;
	
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
