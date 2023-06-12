/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainview.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:27:34 by svalma            #+#    #+#             */
/*   Updated: 2022/07/17 23:15:11 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_entry(char *values, int argc)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (argc != 2)
		return (0);
	while (values[i] != '\0')
	{
		if (((i % 2) == 0) && (values[i] > '0' && values[i] < '5'))
			n++;
		if ((i % 2) == 1 && values[i] == ' ')
			n++;
		i++;
	}
	if (n != 31)
		return (0);
	if (i != 31)
		return (0);
	else
		return (1);
	return (1);
}

int	*cleanentry(char *entry, int *cleanargv)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (entry[n] != '\0')
	{
		if (entry[n] >= '0' && entry[n] <= '9')
		{
			cleanargv[i] = entry[n] - '0';
			i++;
		}
		n++;
	}
	return (cleanargv);
}					
