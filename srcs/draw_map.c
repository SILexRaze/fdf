/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:41:47 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/30 14:46:09 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}


static void	project_draw(int **tab, int x, int y, int zoom, t_data *data)
{
	int	x_proj_or = x;
	int	y_proj_or = y;
	int xn_proj = x + 1;
	int	yn_proj = y + 1;
	int	offset = 300;

	iso(&x, &y, tab[y][x]);
	iso(&xn_proj, &y_proj_or, tab[y_proj_or][xn_proj]);
	draw_line(
		x * zoom + offset,
		y * zoom + offset,
		xn_proj * zoom + offset,
		y_proj_or * zoom + offset,
		data
	);
	iso(&x_proj_or, &yn_proj, tab[yn_proj][x_proj_or]);
	draw_line(
		x * zoom + offset,
		y * zoom + offset,
		x_proj_or * zoom + offset,
		yn_proj * zoom + offset,
		data
	);
}

void	draw_map(t_data *data)
{
	int	coord[2];
	int	zoom;

	coord[0] = 0;
	zoom = 30;
	while (data->tab[coord[0] + 1])
	{
		coord[1] = 1;
		while (coord[1] < data->tab[coord[0]][0] - 1)
		{
			project_draw(data->tab, coord[1], coord[0], zoom, data);
			coord[1]++;
		}
		coord[0]++;
	}
}
