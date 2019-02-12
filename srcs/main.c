/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:22:06 by vifonne           #+#    #+#             */
/*   Updated: 2019/02/12 04:56:30 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
			exit(0);
		read_stdin(data, av[1]);
//		ft_print_list(&data->raw_input);
		parsing(data);
//		print_double_tab_int(data->tab);
		window_setup(data);
		t_point ps, pe;
		ps.x = WIN_W/2;
		ps.y = 0;
		pe.x = WIN_W/2;
		pe.y = WIN_H;
		draw_line(ps, pe, data);
		ps.x = 0;
		ps.y = WIN_H/2;
		pe.x = WIN_W;
		pe.y = WIN_H/2;
		draw_line(ps, pe, data);
		draw_map(data);
		mlx_hook(data->win, 2, 0L, key_press, data);
		mlx_loop(data->mlx_ptr);
	}
	return (0);
}
