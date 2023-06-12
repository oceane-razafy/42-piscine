/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:00:46 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/19 23:17:22 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_search(long root, long nbr)
{
	while (root * root < nbr)
		root = root + 2;
	return (root);
}

int	ft_near_sqrt(int nb)
{
	long	root;
	long	nbr;

	nbr = (long)nb;
	if (nbr < 0)
		return (0);
	if ((nbr % 2) == 0)
		root = 0;
	else
		root = 1;
	return ((int)ft_search(root, nbr));
}

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	if (nb == 3)
		return (1);
	i = 3;
	while (i <= ft_near_sqrt(nb))
	{
		if ((nb % i) == 0)
			return (0);
		i = i + 2;
	}
	return (1);
}
