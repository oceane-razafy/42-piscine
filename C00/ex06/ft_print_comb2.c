/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:26:54 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/06 19:21:53 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_char_to_int(char a, char b)
{
	return ((a % '0') * 10 + (b % '0'));
}

void	ft_print_number(char i, char j, char k, char *l)
{
	if (ft_char_to_int(i, j) < ft_char_to_int(k, *l))
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, " ", 1);
		write(1, &k, 1);
		write(1, l, 1);
		if (!(i == '9' && j == '8' && k == '9' && *l == '9'))
			write(1, ", ", 2);
	}
	(*l)++;
}

void	ft_print_comb2(void)
{
	char	i;
	char	j;
	char	k;
	char	l;

	i = '0';
	while (i <= '9')
	{
		j = '0';
		while (j <= '9')
		{
			k = '0';
			while (k <= '9')
			{
				l = '0';
				while (l <= '9')
				{
					ft_print_number(i, j, k, &l);
				}
				k++;
			}
			j++;
		}
		i++;
	}
}
