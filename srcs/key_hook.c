/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:50:29 by vifonne           #+#    #+#             */
/*   Updated: 2019/04/22 17:39:20 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int keycode, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (keycode == 53)
	{
		mlx_clear_window(data->mlx_ptr, data->win);
		mlx_destroy_window(data->mlx_ptr, data->win);
		exit(0);
	}
	return (0);
}
