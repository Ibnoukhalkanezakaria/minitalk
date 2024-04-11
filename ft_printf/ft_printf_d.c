/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:12:49 by zibnoukh          #+#    #+#             */
/*   Updated: 2023/12/06 16:03:13 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_d(int n, int *length)
{
	long	number;
	long	newnumber;
	int		one;

	number = n;
	one = 1;
	if (number < 0)
	{
		ft_putchar('-', length);
		number *= -1;
	}
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
