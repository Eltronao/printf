/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:42:46 by lagonzal          #+#    #+#             */
/*   Updated: 2022/10/04 14:51:58 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	n;

	n = 0;
	while (s1[n] && s2[n] && s1[n] == s2[n])
		n++;
	return (s1[n] - s2[n]);
}

int	ft_strlen(char *s1)
{
	int	n;

	n = 0;
	while (s1[n])
		n++;
	return (n);
}

void	ft_negative(int *nbr, int *n)
{
	write(1, "-", 1);
	*nbr = *nbr * -1;
	*n += 1;
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
		return (*n);
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
