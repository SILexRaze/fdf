/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:22:06 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/30 12:42:55 by vifonne          ###   ########.fr       */
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
		print_double_tab_int(data->tab);
	}
	return (0);
}
