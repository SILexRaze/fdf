/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:22:14 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/30 14:36:27 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(int x0, int y0, int x1, int y1, t_data *data) {
 
  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;
 
  for(;;){
	mlx_pixel_put(data->mlx_ptr, data->win, x0, y0, 0xFFFFFF);
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}

/*void	draw_line(int x0, int y0, int x1, int y1, t_data *data)
{
	if (x1 == x0)
		draw_vert_line(x0, y0, y1, data);
	else
		draw_default_line(x0, y0, x1, y1, data);
}

void	draw_default_line(int x0, int y0, int x1, int y1, t_data *data)
{
	int	x;
	int	y;
	int	d;

	y = y0;
	x = x0;
	d = 2 * ((y1 - y0) - (x1 - x0));
	while (x < x1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win, x, y, 0xFFFFFF);
		if (d > 0)
		{
			y++;
			d = d - 2 * (x1 - x0);
		}
		d += 2 * (y1 - y0);
		x++;
	}
}

void	draw_vert_line(int x0, int y0, int y1, t_data *data)
{
	int	y;

	y = y0;
	while (y < y1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win, x0, y, 0xFFFFFF);
		y++;
	}
}*/
