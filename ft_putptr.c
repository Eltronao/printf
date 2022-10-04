/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:18:20 by lagonzal          #+#    #+#             */
/*   Updated: 2022/10/04 14:52:37 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

static const char	*g_base = "0123456789abcdef";

int	ft_putptr(unsigned long long int ptr, int *n)
{
	write (1, "0x", 2);
	ft_putnbr_basep_n(ptr, g_base, n);
	return (*n + 2);
}

/*int	main(void)
{
	int	n;
	char	*ptr = "";

	n = 0;
	printf("%p\n", ptr);
	ft_putptr(ptr, &n);
	return (0);	
}*/
