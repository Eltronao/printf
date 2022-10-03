/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_baseh_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:31:36 by lagonzal          #+#    #+#             */
/*   Updated: 2022/10/03 21:38:02 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_baseh_n(unsigned int nbr, const char *base, int *n)
{
	int	m;

	if (nbr >= 16)
	{
		ft_putnbr_baseh_n(nbr / 16, base, n);
		m = nbr % 16;
		write (1, &base[m], 1);
		*n = *n + 1;
	}
	else
	{
		write(1, &base[nbr], 1);
		*n = *n + 1;
	}
	return (*n);
}
