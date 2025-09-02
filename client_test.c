#include <libc.h>
int main (int arc, char **arv)
{
	(void)arc;
	kill((pid_t)atoi(arv[1]), SIGSEGV);
	return (0);
}