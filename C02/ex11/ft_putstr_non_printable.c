/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:11:06 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/11 21:41:47 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isprintable(unsigned char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	ft_char_to_hex(unsigned char c)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &base[c / 16 % 16], 1);
	write(1, &base[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	if (*str == 0)
		return ;
	while (*str)
	{
		if (ft_isprintable(*str))
			write(1, str, 1);
		else
			ft_char_to_hex(*str);
		str++;
	}
}
