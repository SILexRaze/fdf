/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:41:47 by vifonne           #+#    #+#             */
/*   Updated: 2019/04/22 17:17:03 by vifonne          ###   ########.fr       */
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

static void		draw_last_right_line(t_data *data, t_point i, int zoom)
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
	p_np.x = p.x - 1 * zoom;
	p_np.y = p.y + 1 * zoom;
	iso(&p_np.x, &p_np.y, data->tab[i.y + 1][i.x] * zoom);
	draw_line(p_p, p_np, data);
}

static void		draw_last_bot_line(t_data *data, t_point i, int zoom)
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
			if (p.y == ft_list_size(&data->raw_input) - 2)
				draw_last_bot_line(data, (t_point){p.x, p.y + 1}, zoom);
			project_draw(data, p, zoom);
			p.x++;
		}
		draw_last_right_line(data, p, zoom);
		p.y++;
	}
}
