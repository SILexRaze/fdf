/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:33:06 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/30 12:46:52 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

// TO BE REMOVED
void	print_double_tab_int(int **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 1;
		while (j < tab[i][0])
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
