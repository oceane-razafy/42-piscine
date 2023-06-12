/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:27:51 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/10 17:01:21 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(long long x, char edge, char middle)
{
	long long	i;

	i = 0;
	while (i < x)
	{
		if (i == 0 || i == (x - 1))
			ft_putchar(edge);
		else
			ft_putchar(middle);
		i++;
	}
	ft_putchar('\n');
}

void	rush00(long long x, long long y)
{
	long long	i;

	if (x <= 0 || y <= 0)
		return ;
	i = 1;
	ft_print_line(x, 'o', '-');
	while (i > 0 && i < (y - 1))
	{
		ft_print_line(x, '|', ' ');
		i++;
	}
	if (i == y - 1)
		ft_print_line(x, 'o', '-');
}
