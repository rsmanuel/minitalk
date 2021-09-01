#include "minitalk.h"
#include <stdio.h>

void	send_to_server(int pid, char *message)
{
	int bit;
	int i;

	i = 0;
	while (message[i] != '\0')
	{
		bit = -1;
		while(++bit < 8)
		{
			if (message[i] & (128 >> bit))
			{
				kill(pid, SIGUSR2);
			}
			else
			{
				kill(pid, SIGUSR1);
			}
			usleep(10);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
    int pid;

    if (argc != 3)
	{
		ft_putstr_fd("Invalid arguments.\n", 1);
		ft_putstr_fd("Correct format: [./client <PID> <message>]\n", 1);
	}
    else
	{
        pid = atoi(argv[1]);
		send_to_server(pid, argv[2]);
	}
}