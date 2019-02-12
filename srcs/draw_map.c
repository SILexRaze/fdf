/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:41:47 by vifonne           #+#    #+#             */
/*   Updated: 2019/02/12 04:56:16 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

static void		project_draw(t_data *data, t_point i, int zoom)
{
	t_point	p;
	t_point	p_p;
	t_point	p_np;

	p = i;
	p.x *= zoom;
	p.y *= zoom;
	p_p.x = p.x - 1 * zoom;
	p_p.y = p.y;
	iso(&p_p.x, &p_p.y, data->tab[i.y][i.x] * zoom);
	p_np.x = p.x;
	p_np.y = p.y;
	iso(&p_np.x, &p_np.y, data->tab[i.y][i.x + 1] * zoom);
	draw_line(p_p, p_np, data);
	p_np.x = p.x - 1 * zoom;
	p_np.y = p.y + 1 * zoom;
	iso(&p_np.x, &p_np.y, data->tab[i.y + 1][i.x] * zoom);
	draw_line(p_p, p_np, data);
}

static int		max_width(int **tab)
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

static int		max_zoom(t_data *data)
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

void			draw_map(t_data *data)
{
	t_point	p;
	int		zoom;

	p.y = 0;
	zoom = max_zoom(data);
	data->offset.x = WIN_W / 2 - max_width(data->tab)/2;
	data->offset.y = WIN_H / 2 - (itab_len(data->tab) * zoom)/2;
	while (data->tab[p.y + 1])
	{
		p.x = 1;
		while (p.x < data->tab[p.y][0] - 1)
		{
			project_draw(data, p, zoom);
			p.x++;
		}
		p.y++;
	}
}
