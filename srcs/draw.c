/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:22:14 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/30 11:50:18 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(int x0, int y0, int x1, int y1, t_data *data)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			draw_line_low(x1, y1, x0, y0, data);
		else
			draw_line_low(x0, y0, x1, y1, data);
	}
	else
	{
		if (y0 > y1)
			draw_line_high(x1, y1, x0, y0, data);
		else
			draw_line_high(x0, y0, x1, y1, data);
	}
}

void	draw_line_low(int x0, int y0, int x1, int y1, t_data *data)
{
	int	y_inc;
	int	dy;
	int	x;
	int	y;
	int	D;

	y_inc = 1;
	dy = y1 - y0;
	if (dy < 0)
	{
		y_inc = -1;
		dy = -dy;
	}
	D = 2 * dy - (x1 - x0);
	x = x0;
	y = y0;
	while (x < x1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win, x, y, 0xFFFFFF);
		if (D > 0)
		{
			y += y_inc;
			D -= 2 * (x1 - x0);
		}
		D += 2 * dy;
	}
}

void	draw_line_high(int x0, int y0, int x1, int y1, t_data *data)
{
	int	x_inc;
	int	dx;
	int	x;
	int	y;
	int	D;

	x_inc = 1;
	dx = x1 - x0;
	if (dx < 0)
	{
		x_inc = -1;
		dx = -dx;
	}
	D = 2 * dx - (y1 - x0);
	x = x0;
	y = y0;
	while (y < y1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win, x, y, 0xFFFFFF);
		if (D > 0)
		{
			x += x_inc;
			D -= 2 * (y1 - y0);
		}
		D += 2 * dx;
	}
}
