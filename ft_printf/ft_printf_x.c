/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:17:44 by zibnoukh          #+#    #+#             */
/*   Updated: 2023/12/06 16:05:38 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_x(unsigned int n, int *length)
{
	unsigned int	character;
	unsigned int	newcharacter;
	unsigned int	one;
	char			*hexadecimal_chars;

	hexadecimal_chars = "0123456789abcdef";
	character = n;
	one = 1;
	while (character / one >= 16)
		one *= 16;
	while (one > 0)
	{
		newcharacter = character / one;
		ft_putchar(hexadecimal_chars[newcharacter], length);
		character %= one;
		one /= 16;
	}
}
