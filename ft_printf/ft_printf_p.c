/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:30:26 by zibnoukh          #+#    #+#             */
/*   Updated: 2023/12/06 17:01:35 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_xxx(unsigned long n, int *length)
{
	unsigned long	character;
	unsigned long	newcharacter;
	unsigned long	one;
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

void	ft_printf_p(void *ptr, int *length)
{
	unsigned long	p;

	p = (unsigned long)ptr;
	if (ptr == NULL)
	{
		ft_printf_s("(nil)", length);
		return ;
	}
	ft_printf_s("0x", length);
	ft_printf_xxx(p, length);
}
