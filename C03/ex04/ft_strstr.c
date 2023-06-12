/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:23:51 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/13 21:14:27 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n && s1[i] == s2[i])
		i++;
	if (i == n)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	n;

	if ((*str == 0) && (*to_find == 0))
		return (str);
	if (*to_find == 0)
		return (str);
	if (*str == 0)
		return (0);
	n = ft_strlen(to_find);
	while (*str)
	{
		while (*str != *to_find && *str)
			str++;
		if (ft_strncmp(str, to_find, n) == 0)
			return (str);
		if (*str != 0)
			str++;
	}
	return (0);
}
