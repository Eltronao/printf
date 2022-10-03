/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:22:10 by lagonzal          #+#    #+#             */
/*   Updated: 2022/10/03 21:38:05 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include<stddef.h>
#include<unistd.h>
#include<stdio.h>
#include "ft_printf.h"

static const char *g_hex = "0123456789abcdef";
static const char *g_hexup = "0123456789ABCDEF";

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_select(char slctr, va_list arg_ptr)
{
	int	n;

	n = 0;
	if (slctr == 'c')
		n = ft_putchar(va_arg(arg_ptr, int));
	else if (slctr == 's')
		n = ft_putstr_n(va_arg(arg_ptr, char *));
	else if (slctr == 'p')
		n = ft_putptr(va_arg(arg_ptr, unsigned long long int), &n);
	else if (slctr == 'd' || slctr == 'i')
		n = ft_putnbr_base_n(va_arg(arg_ptr, int), "0123456789", &n);
	else if (slctr == 'u')
		n = ft_putunbr_n(va_arg(arg_ptr, unsigned int), &n);
	else if (slctr == 'x')
	n = ft_putnbr_baseh_n((unsigned int)va_arg(arg_ptr, int), g_hex, &n);
	else if (slctr == 'X')
		n = ft_putnbr_baseh_n((unsigned int)va_arg(arg_ptr, int), g_hexup, &n);
	else if (slctr == '%')
	{
		write(1, "%", 1);
		n++;
	}
	return (n);
}

int	ft_printf(char const *s, ...)
{
	va_list	arg_ptr;
	size_t	n;
	size_t	m;

	n = -1;
	m = 0;
	va_start(arg_ptr, s);
	while (s[++n])
	{
		if (s[n] == '%')
		{
			n++;
			m = m + ft_select(s[n], arg_ptr) - 2;
		}
		else
			ft_putchar(s[n]);
	}
	va_end(arg_ptr);
	return (n + m);
}

int	main(void)
{
	char	c = 'c';
	char	*s = "string";
	int		num = 425345;
	ft_printf("pointer: %p\n", -1);
	return (0);
}
