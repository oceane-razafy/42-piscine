/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:00:32 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/06 21:15:31 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_minus(int *nb)
{
	if (*nb < 0)
	{
		*nb = -(*nb);
		write(1, "-", 1);
	}
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

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	ft_print_minus(&nb);
	nb_digits = ft_compute_digits(nb);
	while (nb_digits > 0)
	{
		digit = (nb / ft_power(10, (nb_digits - 1))) % 10;
		digit_char = '0' + digit;
		write(1, &digit_char, 1);
		nb_digits--;
	}
}
