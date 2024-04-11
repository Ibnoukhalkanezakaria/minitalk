/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:44:39 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/03/09 15:29:49 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	message_received(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("%s\n", "Message received!");
	else
		ft_printf("%s\n", "Message received!");
}

void	send_signal(int pid, int signal)
{
	if (kill(pid, signal) == -1)
	{
		ft_printf("%s\n", "kill");
		return ;
	}
}

void	send_message(int pid, char *message)
{
	int	i;
	int	bit;
	int	j;

	j = 0;
	while (message[j])
	{
		i = 7;
		while (i >= 0)
		{
			bit = (message[j] >> i) & 1;
			if (bit)
				send_signal(pid, SIGUSR1);
			else
				send_signal(pid, SIGUSR2);
			usleep(300);
			i--;
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, &message_received);
	signal(SIGUSR2, &message_received);
	if (ac != 3)
	{
		ft_printf("%s", "You have to write PID & message!");
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID\n");
		return (0);
	}
	send_message(pid, av[2]);
	return (0);
}
