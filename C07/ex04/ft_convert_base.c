/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:22:50 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/25 00:18:12 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_putnbr_base(int nbr, char *base);
int		ft_strlen2(char *str);

int	ft_checkbase(char *base, int blen)
{
	int	i;
	int	j;

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
		if (*base == '+' || *base == '-' || *base == ' ' || *base == '\f'
			|| *base == '\n' || *base == '\r' || *base == '\t' || *base == '\v')
			return (0);
		base++;
	}
	return (1);
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

int	ft_search_pos(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_convert(char *str_nb, char *base, int blen)
{
	int	i;
	int	len;
	int	result;
	int	pos;

	i = 0;
	while (ft_search_pos(str_nb[i], base) != -1)
		i++;
	len = i;
	i = 0;
	result = 0;
	while (i < len)
	{
		pos = ft_search_pos(str_nb[len - 1 - i], base);
		if (pos == -1)
			return (0);
		result = result + pos * ft_power(blen, i);
		i++;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;
	int		blen;

	blen = ft_strlen2(base_from);
	if (ft_checkbase(base_from, blen) == 0
		|| ft_checkbase(base_to, ft_strlen2(base_to)) == 0)
		return (NULL);
	sign = 1;
	while ((*nbr == ' ' || *nbr == '\f' || *nbr == '\n' || *nbr == '\r'
			|| *nbr == '\t' || *nbr == '\v') && *nbr)
		nbr++;
	while ((*nbr == '-' || *nbr == '+') && *nbr)
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	return (ft_putnbr_base(sign * ft_convert(nbr, base_from, blen), base_to));
}
