/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:42:46 by lagonzal          #+#    #+#             */
/*   Updated: 2022/09/30 20:54:02 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	ft_negative(int *nbr, int *n)
{
	write(1, "-", 1);
	*nbr = *nbr * -1;
	*n = *n + 1;
}

void	ft_special(int *n, char *bases)
{
	if (ft_strcmp(bases, "0123456789") == 0)
	{
		write(1, "-2147483648", 11);
		*n += 11;
	}
	else if (ft_strcmp(bases, "0123456789ABCDEF") == 0)
	{
		write (1, "-7FFFFFFF", 9);
		*n += 9;
	}
	else if (ft_strcmp(bases, "0123456789abcdef") == 0)
	{	
		write (1, "-7fffffff", 9);
		*n += 9;
	}
}

int	ft_putnbr_base_n(int nbr, char *bases, int *n)
{
	int	m;
	int	base;

	base = ft_strlen(bases);
	if (-2147483647 - 1 == nbr)
	{
		ft_special(n, bases);
		return (n);
	}
	if (nbr < 0)
		ft_negative(&nbr, n);
	if (nbr >= base)
	{
		ft_putnbr_base_n(nbr / base, bases, n);
		m = nbr % base;
		write (1, &bases[m], 1);
		*n = *n + 1;
	}
	else
	{
		write(1, &bases[nbr], 1);
		*n = *n + 1;
	}
	return (*n);
}

int	main(void)
{
	int	n;
	n = 5;
	n = ft_putnbr_base_n(-2147483648 , "0123456789ABCDEF", &n);
	printf("\n");
	printf("%d", n);
	return (0);
}
