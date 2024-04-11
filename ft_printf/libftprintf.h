/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:07:05 by zibnoukh          #+#    #+#             */
/*   Updated: 2023/12/06 16:05:42 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *length);
void	ft_printf_s(char *s, int *length);
void	ft_printf_d(int n, int *length);
void	ft_printf_p(void *ptr, int *length);
void	ft_printf_u(unsigned int n, int *length);
void	ft_printf_x(unsigned int n, int *length);
void	ft_printf_xx(unsigned int n, int *length);
void	ft_printf_xxx(unsigned long n, int *length);

#endif
