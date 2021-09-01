#include "minitalk.h"

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static int	dec = 255;
	static int	bit = 0;
	int			pid;

	if (signum == SIGUSR1)
		dec = dec ^ (128 >> bit);
	else if (signum == SIGUSR2)
		dec = dec | (128 >> bit);
	bit++;
	if (bit == 8)
	{
		if (dec == 0)
		{
			pid = info->si_pid;
			if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		write(1, &dec, 1);
		dec = 255;
		bit = 0;
	}
	(void)context;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_putcolor_fd(ANSI_COLOR_GREEN, "PID: ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	action.sa_flags = SA_SIGINFO;
	action.sa_handler = NULL;
	action.sa_sigaction = handler_sigusr;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
