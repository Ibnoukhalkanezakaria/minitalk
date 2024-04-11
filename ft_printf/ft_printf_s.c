/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:02:18 by zibnoukh          #+#    #+#             */
/*   Updated: 2023/12/01 17:34:41 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_s(char *s, int *length)
{
	int	i;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		*length += 6;
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		(*length)++;
		i++;
	}
}
