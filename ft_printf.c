/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:22:10 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/30 20:54:05 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include<stddef.h>
#include<unistd.h>
#include "libprint.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_var_check(const char *s)
{
	size_t	n;
	size_t	var;

	n = -1;
	var = 0;
	while (s[++n])
	{
		if (s[n] == '%' && s[n - 1] != '%' && s[n + 1] != '%')
			var++;
	}
	return (var);
}

int	ft_select(char slctr, va_list arg_ptr)
{
	int	n;

	n = 0;
	if (slctr == 'c')
		n = ft_putchar_n(va_arg(arg_ptr, int));
	else if (slctr == 's')
		n = ft_putstr_n(va_arg(arg_ptr, char *));
//	else if (slctr == 'p')
//		n = ft_putptr(var_arg(arg_ptr, ));
	else if (slctr == 'd' || slctr == 'i')
		n = ft_putnbr_base_n(va_arg(arg_ptr, int), "0123456789", &n);
	else if (slctr == 'u')
		n = ft_put_unbr_n(var_arg(arg_ptr, unsigned int));
	else if (slctr == 'x')
	n = ft_putnbr_base_n(var_arg(arg_ptr, int), "0123456789abcdef");
	else if (slctr == 'X')
		n = ft_put_uhnbr_n(var_arg(arg_ptr, int), "0123456789ABCDEF");
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
			m = m + ft_select(s[n], arg_ptr);
		}
		else
			ft_putchar(s[n]);
	}
	return (n + m);
}

int	main(void)
{
	char	c = 'c';
	char	*s = "string";
	int		num = 425345;
	ft_printf("%d \n", num);
	return (0);
}
