/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:22:14 by vifonne           #+#    #+#             */
/*   Updated: 2019/02/12 04:18:54 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	apply_offset(t_point *ps, t_point *pe, int offset)
{
	ps->x += offset;
	ps->y += offset;
	pe->x += offset;
	pe->y += offset;
}

void		draw_line(t_point ps, t_point pe, t_data *data)
{
	t_point	d;
	t_point	s;
	int		err;
	int		err2;

	apply_offset(&ps, &pe, data->offset);
	d.x = abs(pe.x-ps.x);
	s.x = ps.x<pe.x ? 1 : -1;
	d.y = abs(pe.y-ps.y);
	s.y = ps.y<pe.y ? 1 : -1; 
	err = (d.x>d.y ? d.x : -d.y)/2;
	while (1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win, ps.x, ps.y, 0xFFFFFF);
		if (ps.x==pe.x && ps.y==pe.y)
			break;
		err2 = err;
		if (err2 >-d.x)
		{
			err -= d.y;
			ps.x += s.x;
		}
		if (err2 < d.y)
		{
			err += d.x;
			ps.y += s.y;
		}
	}
}


