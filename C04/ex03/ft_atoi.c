/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:53:20 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/14 18:44:23 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_char_to_int(char *str)
{
	int	i;
	int	nb;

	i = 1;
	nb = str[0] % '0';
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + str[i] % '0';
		i++;
	}
	return (nb);
}

int	ft_atoi(char *str)
{
	int		sign;
	char	*str_nb;

	if (*str == 0)
		return (0);
	sign = 1;
	while (ft_isspace(*str) && *str)
		str++;
	if ((*str > '9' || *str < '0') && (*str != '+') && (*str != '-'))
		return (0);
	str_nb = str;
	if (*str == '+' || *str == '-')
	{
		while ((*str == '+' || *str == '-') && (*str))
		{
			if (*str == '-')
				sign *= -1;
			str++;
		}
		str_nb = str;
		if (*str > '9' || *str < '0')
			return (0);
	}
	return (sign * ft_char_to_int(str_nb));
}
