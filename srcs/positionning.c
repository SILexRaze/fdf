/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positionning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:12:01 by vifonne           #+#    #+#             */
/*   Updated: 2019/04/22 17:22:37 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		max_width(int **tab)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (tab[i])
	{
		if (tab[i][0] > max)
			max = tab[i][0];
		i++;
	}
	return (max);
}

int		max_zoom(t_data *data)
{
	int	i;
	int	max_w;
	int	max_h;
	int	margin;

	i = 1;
	margin = 100;
	max_w = max_width(data->tab);
	max_h = itab_len(data->tab);
	while (i * max_w < WIN_W/2 - margin && i * max_h < WIN_H/2 - margin)
		i++;
	return (i);
}
