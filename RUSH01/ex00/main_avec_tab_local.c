/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_avec_tab_local.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:38:08 by orazafy           #+#    #+#             */
/*   Updated: 2022/07/17 23:39:30 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_notduplicate(int x, int y, int n, int **tab);
int	ft_view1(int x, int **tab, int *view);
int	ft_view2(int x, int **tab, int *view);
int	ft_view3(int y, int **tab, int *view);
int	ft_view4(int y, int **tab, int *view);
int	ft_generate_tab(int **tab, int *view);
int	check_entry(char *values, int argc);
int	*cleanentry(char *entry, int *cleanargv);

int	ft_check(int x, int y, int **tab, int *view)
{
	int	n;

	n = 1;
	while (n < 5)
	{
		tab[y][x] = n;
		if ((ft_notduplicate(x, y, n, tab))
			&& (ft_view1(x, tab, view))
			&& (ft_view2(x, tab, view)) && (ft_view3(y, tab, view))
			&& (ft_view4(y, tab, view)))
		{
			tab[y][x] = n;
			if (ft_generate_tab(tab, view))
				return (1);
		}
		n++;
	}
	return (0);
}

int	ft_generate_tab(int **tab, int *view)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tab[y][x] == 0)
			{	
				if (ft_check(x, y, tab, view))
					return (1);
				tab[y][x] = 0;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_print(int **tab)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = tab[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_free(int **tab, int *view)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	free(view);
}

int	main(int argc, char **argv)
{
	int		i;
	int		**tab;
	int		e;
	int		*view;

	e = check_entry(argv[1], argc);
	if (e == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}	
	view = (int *)malloc(sizeof(int) * 16);
	view = cleanentry(argv[1], view);
	tab = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
	{
		tab[i] = (int *)malloc(sizeof(int) * 4);
		i++;
	}
	ft_generate_tab(tab, view);
	ft_print(tab);
	ft_free(tab, view);
	return (0);
}
