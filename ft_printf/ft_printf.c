/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:07:18 by zibnoukh          #+#    #+#             */
/*   Updated: 2023/12/06 16:03:48 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	f(const char *format, va_list args, int *length)
{
	if (*format == 's')
		ft_printf_s(va_arg(args, char *), length);
	else if (*format == 'd' || *format == 'i')
		ft_printf_d(va_arg(args, int), length);
	else if (*format == 'p')
		ft_printf_p(va_arg(args, void *), length);
	else if (*format == 'u')
		ft_printf_u(va_arg(args, unsigned int), length);
	else if (*format == 'x')
		ft_printf_x(va_arg(args, unsigned int), length);
	else if (*format == 'X')
		ft_printf_xx(va_arg(args, unsigned int), length);
}

static void	ft_format(const char *format, va_list args, int *length)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				ft_putchar((char)va_arg(args, int), length);
			else if (*format == '%')
				ft_putchar('%', length);
			else if (*format == '\0')
			{
				*length = -1;
				return ;
			}
			else
				f(format, args, length);
		}
		else
			ft_putchar(*format, length);
		format++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		length;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	length = 0;
	ft_format(format, args, &length);
	va_end(args);
	return (length);
}
