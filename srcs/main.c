/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:22:06 by vifonne           #+#    #+#             */
/*   Updated: 2019/04/22 17:34:06 by vifonne          ###   ########.fr       */
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
		parsing(data);
		window_setup(data);
		draw_map(data);
		mlx_hook(data->win, 2, 0L, key_press, data);
		mlx_loop(data->mlx_ptr);
	}
	return (0);
}
