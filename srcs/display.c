/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:12:21 by vifonne           #+#    #+#             */
/*   Updated: 2019/02/12 04:19:52 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	window_setup(t_data *data)
{
	if (!(data->mlx_ptr = mlx_init()))
		error(-1);
	if (!(data->win = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "fdf")))
		error(-1);
	mlx_clear_window(data->mlx_ptr, data->win);
}
