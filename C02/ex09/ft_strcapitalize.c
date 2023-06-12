/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:28:30 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/12 14:53:53 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalphanum(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (!(ft_isalphanum(str[i])) && str[i])
		i++;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - ('a' - 'A');
	if (str[i] != 0)
		i++;
	while (str[i])
	{
		while (ft_isalphanum(str[i]) && str[i])
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + ('a' - 'A');
			i++;
		}
		while (!(ft_isalphanum(str[i])) && str[i])
			i++;
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ('a' - 'A');
		i++;
	}
	return (str);
}
