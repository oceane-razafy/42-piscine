/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:58:52 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/23 22:11:22 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_compute_digits(int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_power(int n, int power)
{
	int	result;

	result = 1;
	while (power > 0)
	{
		result *= n;
		power--;
	}
	return (result);
}

void	ft_putnbr(int nb)
{
	int		nb_digits;
	int		digit;
	char	digit_char;

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	nb_digits = ft_compute_digits(nb);
	while (nb_digits > 0)
	{
		digit = (nb / ft_power(10, (nb_digits - 1))) % 10;
		digit_char = '0' + digit;
		write(1, &digit_char, 1);
		nb_digits--;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
