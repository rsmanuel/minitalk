#include "minitalk.h"

void	send_to_server(int pid, char *message)
{
	int	bit;
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(message);
	while (i <= len)
	{
		bit = -1;
		while (++bit < 8)
		{
			if (message[i] & (128 >> bit))
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(EXIT_FAILURE);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(EXIT_FAILURE);
			}
			usleep(30);
		}
		i++;
	}
}

void	handler_sigusr(int signum, siginfo_t *info, void *contexts)
{
	(void)info;
	(void)contexts;
	if (signum == SIGUSR1)
		ft_putcolor_fd(ANSI_COLOR_CYAN, "Client: Message received by Server!\n", 1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	action;

	if (argc != 3)
	{
		ft_putcolor_fd(ANSI_COLOR_RED, "Invalid arguments.\n", 1);
		ft_putcolor_fd(ANSI_COLOR_YELLOW, "Correct format: [./client <PID> <message>]\n", 1);
	}
	else
	{
		pid = atoi(argv[1]);
		action.sa_flags = SA_SIGINFO;
		action.sa_handler = NULL;
		action.sa_sigaction = handler_sigusr;
		sigaction(SIGUSR1, &action, NULL);
		send_to_server(pid, argv[2]);
	}
	return (0);
}
