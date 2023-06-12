/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:34:56 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/24 17:01:32 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_srch(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int		nb_words;
	char	*start;

	nb_words = 0;
	while (*str)
	{
		while (ft_srch(*str, charset) == 1 && *str)
			str++;
		start = str;
		while (ft_srch(*str, charset) == 0 && *str)
			str++;
		if (str - start > 0)
			nb_words++;
		if (*str != 0)
			str++;
	}
	return (nb_words);
}

int	ft_len(char *str, char *charset)
{
	char	*start;

	start = str;
	while (ft_srch(*str, charset) == 0 && *str)
		str++;
	return (str - start);
}

char	*ft_strndup(char *str, int n)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (str[i] && i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		nb_words;
	char	**tab;
	int		i;
	int		j;

	nb_words = ft_count_words(str, charset);
	tab = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (tab == NULL)
		return (0);
	i = 0;
	j = 0;
	while (j < nb_words && str[i])
	{
		while (ft_srch(str[i], charset) == 1 && str[i])
			i++;
		tab[j] = ft_strndup(&str[i], ft_len(&str[i], charset));
		i = i + ft_len(&str[i], charset);
		if (str[i] != 0)
			i++;
		j++;
	}
	tab[nb_words] = 0;
	return (tab);
}
