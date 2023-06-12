/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:01:09 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/18 19:44:38 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	char	*str_nb;
	int		blen;

	blen = 0;
	while (base[blen])
		blen++;
	if (ft_checkbase(base, blen) == 0)
		return (0);
	sign = 1;
	while ((*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
			|| *str == '\t' || *str == '\v') && *str)
		str++;
	if (ft_search_pos(*str, base) == -1 && *str != '+' && *str != '-')
		return (0);
	str_nb = str;
	if (*str_nb == '-' || *str_nb == '+')
	{
		if (*str_nb == '-')
			sign = -1;
		str_nb++;
	}
	return (sign * ft_convert(str_nb, base, blen));
}
