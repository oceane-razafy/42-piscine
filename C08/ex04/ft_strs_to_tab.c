/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:56:14 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/23 22:46:43 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s_result;
	int			i;

	i = 0;
	s_result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (s_result == NULL)
		return (0);
	while (i < ac)
	{
		s_result[i].size = ft_strlen(av[i]);
		s_result[i].str = av[i];
		s_result[i].copy = ft_strdup(av[i]);
		i++;
	}
	s_result[i].size = 0;
	s_result[i].str = 0;
	s_result[i].copy = 0;
	return (s_result);
}
