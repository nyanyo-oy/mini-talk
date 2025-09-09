#include "minitalk.h"

int server()
{
	pid_t	pid;
	struct sigaction sa;
	pid =  getpid();
	ft_printf("Server PID: %d\n", pid);
	
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

int	main(void)
{
	server();
}