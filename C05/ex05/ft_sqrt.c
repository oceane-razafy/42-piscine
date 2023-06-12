/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:54:38 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/19 22:36:51 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_search(long root, long nbr)
{
	while (root * root < nbr)
		root = root + 2;
	if (root * root == nbr)
		return (root);
	return (0);
}

int	ft_sqrt(int nb)
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
