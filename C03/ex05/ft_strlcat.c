/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:29:16 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/13 18:51:47 by orazafy          ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < nb)
	{
		dest[len++] = src[i];
		i++;
	}
	dest[len] = 0;
	return (dest);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len;

	len = ft_strlen(dest);
	if (size > len + 1)
		ft_strncat(dest, src, size - len - 1, len);
	if (size < len)
		return (size + ft_strlen(src));
	else
		return (len + ft_strlen(src));
}
