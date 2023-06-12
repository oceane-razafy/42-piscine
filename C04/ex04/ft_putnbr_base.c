/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:15:41 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/18 21:17:16 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long long	ft_strlen(char *str)
{
	long long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_checkbase(char *base, long long blen)
{
	long long	i;
	long long	j;

	if (base[0] == 0 || base[1] == 0)
		return (0);
	i = 0;
	while (i < (blen - 1))
	{
		j = i + 1;
		while (j < blen)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		base++;
	}
	return (1);
}

long long	ft_strlen_result(long long nb, long long blen)
{
	long long	i;
	long long	quotient;

	quotient = nb;
	i = 0;
	while (quotient > 0)
	{
		quotient = quotient / blen;
		i++;
	}
	if (nb == 0)
		i = 1;
	return (i);
}

int	ft_convert(char *result, long long nb, char *base, long long rlen)
{
	long long	i;
	long long	quotient;
	long long	pos;
	long long	blen;

	quotient = nb;
	i = 0;
	while (base[i])
		i++;
	blen = i;
	i = 0;
	if (nb == 0)
		result[0] = base[0];
	while (quotient > 0)
	{
		pos = quotient % blen;
		if (pos >= blen)
			return (0);
		result[rlen - 1 - i] = base[pos];
		quotient = quotient / blen;
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	blen;
	long long	nb;
	char		result[1000];
	long long	rlen;
	int			error;

	blen = ft_strlen(base);
	if (ft_checkbase(base, blen) == 0)
		return ;
	nb = (long long)nbr;
	if (nb >= 0)
	{
		rlen = ft_strlen_result(nb, blen);
	}
	else
	{
		result[0] = '-';
		nb = -nb;
		rlen = ft_strlen_result(nb, blen) + 1;
	}
	error = ft_convert(result, nb, base, rlen);
	if (error == 0)
		return ;
	write(1, result, rlen);
}
