#include "minitalk.h"

void	handler_sigusr(int signum)
{
	static char	dec = 0xFF;
	static int	bit = 0;

	while (dec != 0)
	{
		if (signum == SIGUSR1)
		{
			dec ^= 0x80 >> bit;
			//dec = dec ^ (128 >> bit);
		}
		else if (signum == SIGUSR2)
		{
			dec |= 0x80 >> bit;
			//dec = dec | (128 >> bit);
		}
		bit++;
		if (bit == 8)
		{
			write(1, &dec, 1);
			dec = 0xFF;
			bit = 0;
		}
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	while (1)
		pause();
}
