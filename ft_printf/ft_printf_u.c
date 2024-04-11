/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:48:56 by zibnoukh          #+#    #+#             */
/*   Updated: 2023/12/01 17:34:37 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_u(unsigned int n, int *length)
{
	unsigned int	number;
	unsigned int	newnumber;
	unsigned int	one;

	number = n;
	one = 1;
	while (number / one >= 10)
		one *= 10;
	while (one > 0)
	{
		newnumber = number / one;
		ft_putchar(newnumber + 48, length);
		number %= one;
		one /= 10;
	}
}
