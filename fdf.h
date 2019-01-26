/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:41:54 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/26 13:59:36 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win;
}					t_data;

int					key_press(int keycode, void *param);
#endif
