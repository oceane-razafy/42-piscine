/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:20:52 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/10 17:00:35 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush00(long long x, long long y);

int	main(void)
{
	rush00(5, 5);
	rush00(123, 42);
	rush00(5, 3);
	rush00(5, 1);
	rush00(1, 1);
	rush00(1, 5);
	rush00(4, 4);
	rush00(0, 0);
	rush00(-42, -42);
	rush00(-42, 0);
	rush00(0, -42);
	return (0);
}
