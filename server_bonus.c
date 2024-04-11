/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:44:53 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/03/09 15:30:10 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	signal_handler(int signal, siginfo_t *info, void *ctx)
{
	static char	get_character = 0;
	static int	get_bits = 0;

	(void)ctx;
	get_bits++;
	if (signal == SIGUSR1)
	{
		get_character = get_character << 1 | 1;
		kill(info->si_pid, SIGUSR1);
	}
	else if (signal == SIGUSR2)
	{
		get_character = get_character << 1;
		kill(info->si_pid, SIGUSR2);
	}
	if (get_bits == 8 && get_character)
	{
		write(1, &get_character, 1);
		get_bits = 0;
		get_character = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_handler;
	pid = getpid();
	ft_printf("PID is: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
