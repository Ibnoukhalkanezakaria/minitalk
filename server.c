/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:44:53 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/03/09 15:30:17 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	signal_handler(int signal)
{
	static char	get_character = 0;
	static int	get_bits = 0;

	get_bits++;
	if (signal == SIGUSR1)
		get_character = get_character << 1 | 1;
	else if (signal == SIGUSR2)
		get_character = get_character << 1;
	if (get_bits == 8)
	{
		write(1, &get_character, 1);
		get_bits = 0;
		get_character = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID is: %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		;
	return (0);
}
