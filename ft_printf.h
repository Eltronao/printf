/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprint.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:20:00 by lagonzal          #+#    #+#             */
/*   Updated: 2022/10/04 14:50:03 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(char const *s, ...);
int	ft_putchar_n(char c);
int	ft_putnbr_base_n(int nbr, char *bases, int *n);
int	ft_putnbr_baseh_n(int nbr, const char *bases, int *n);
int	ft_putnbr_basep_n(unsigned long long int nbr, const char *base, int *n);
int	ft_putstr_n(char *s);
int	ft_putptr(unsigned long long int ptr, int *n);
int	ft_putunbr_n(unsigned int num, int *n);

#endif
