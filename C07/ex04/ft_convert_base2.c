/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:34:41 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/23 15:32:35 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

long long	ft_strlen(char *str)
{
	long long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

int	ft_convert2(char *result, long long nb, char *base, long long rlen)
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
	result[rlen] = 0;
	return (1);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long long	nb;
	char		*result;
	long long	rlen;

	nb = (long long)nbr;
	if (nb >= 0)
	{
		rlen = ft_strlen_result(nb, ft_strlen(base));
		result = (char *)malloc(sizeof(char) * (rlen + 1));
		if (result == NULL)
			return (NULL);
	}
	else
	{
		nb = -nb;
		rlen = ft_strlen_result(nb, ft_strlen(base)) + 1;
		result = (char *)malloc(sizeof(char) * (rlen + 1));
		if (result == NULL)
			return (NULL);
		result[0] = '-';
	}
	if (ft_convert2(result, nb, base, rlen) == 0)
		return (NULL);
	return (result);
}
