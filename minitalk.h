#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>

#define SUCSSES 1
#define FAILURE 0


extern volatile sig_atomic_t g_task_end;

int server();
int	client(pid_t pid, char *str);

void	setup_sigactoion(struct sigaction *sa, void (*handler)(int, siginfo_t *, void *));
void signal_handler(int signum, siginfo_t *info, void *context);
void	client_task_end_handler(int signum, siginfo_t *info, void *context);
