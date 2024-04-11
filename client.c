/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:44:39 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/03/17 14:16:01 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	send_signal(int pid, int signal)
{
	if (kill(pid, signal) == -1)
	{
		ft_printf("%s\n", "kill");
		exit(1);
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
			usleep(255);
			i--;
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_printf("%s", "You have to write PID & message!");
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID\n");
		exit(1);
	}
	send_message(pid, av[2]);
	return (0);
}
