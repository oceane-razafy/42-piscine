/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:38:10 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/24 16:10:21 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[len++] = src[i];
		i++;
	}
	dest[len] = 0;
	return (dest);
}

int	ft_compute_len(char **strs, int size, char *sep)
{
	int	len;
	int	i;

	if (size == 0)
		return (1);
	len = 0;
	i = 0;
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		if (i < size - 1)
			len = len + ft_strlen(sep);
		i++;
	}
	return (len + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*dest;
	int		i;

	len = ft_compute_len(strs, size, sep);
	dest = (char *)malloc(sizeof(char) * len);
	if (dest == NULL)
		return (0);
	if (size == 0)
	{
		*dest = 0;
		return (dest);
	}
	i = 0;
	*dest = 0;
	while (i < size)
	{
		dest = ft_strcat(dest, strs[i]);
		if (i < size - 1)
			dest = ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}
