/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:50:29 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/26 14:02:50 by vifonne          ###   ########.fr       */
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
		//free(data->win);
		//free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}
