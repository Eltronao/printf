/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:18:20 by lagonzal          #+#    #+#             */
/*   Updated: 2022/10/03 20:54:23 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
static const char	*g_base = "123456789abcdef";

int	ft_putptr(unsigned long long int ptr, int *n)
{
	write (1, "0x", 2);
	ft_putnbr_baseh_n((unsigned int)ptr, g_base, n);
	return (*n + 2);
}

