/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:21:17 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/17 22:16:23 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_notduplicate(int x, int y, int n, int **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if ((tab[i][x] == n) && (i != y))
			return (0);
		i++;
	}
	j = 0;
	while (j < 4)
	{
		if ((tab[y][j] == n) && (j != x))
			return (0);
		j++;
	}
	return (1);
}

int	ft_view1(int x, int **tab, int *view)
{
	int	count;
	int	max;
	int	i;	

	i = 0;
	count = 1;
	max = tab[i][x];
	if (max != 0)
	{
		while (i < 3)
		{
			if (max < tab[i + 1][x])
			{
				max = tab[i + 1][x];
				count++;
			}
			i++;
		}
		if (count > view[x])
			return (0);
	}
	return (1);
}

int	ft_view2(int x, int **tab, int *view)
{
	int	count;
	int	max;
	int	i;

	i = 3;
	count = 1;
	max = tab[i][x];
	if (max != 0)
	{
		while (i > 0)
		{
			if (max < tab[i - 1][x])
			{
				max = tab[i - 1][x];
				count++;
			}
			i--;
		}
		if (count > view[x + 4])
			return (0);
	}
	return (1);
}

int	ft_view3(int y, int **tab, int *view)
{
	int	count;
	int	max;
	int	i;	

	i = 0;
	count = 1;
	max = tab[y][i];
	if (max != 0)
	{
		while (i < 3)
		{
			if (max < tab[y][i + 1])
			{
				max = tab[y][i + 1];
				count++;
			}
			i++;
		}
		if (count > view[y + 8])
			return (0);
	}
	return (1);
}

int	ft_view4(int y, int **tab, int *view)
{
	int	count;
	int	max;	
	int	i;

	i = 3;
	count = 1;
	max = tab[y][i];
	if (max != 0)
	{
		while (i > 0)
		{
			if (max < tab[y][i - 1])
			{
				max = tab[y][i - 1];
				count++;
			}
			i--;
		}
		i = 0;
		if (count > view[y + 12])
			return (0);
	}
	return (1);
}
