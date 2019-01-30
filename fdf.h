/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:41:54 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/30 12:42:08 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# define WIN_W 1024
# define WIN_H 768
typedef struct		s_data
{
	int				**tab;
	void			*mlx_ptr;
	void			*win;
	t_list			*raw_input;
}					t_data;

/*
**	PARSER
*/
void				read_stdin(t_data *data, char *filename);
void				parsing(t_data *data);
char				**split_fdf(char *str);
/*
**	DRAWING FUNCTIONS
*/
void	draw_line(int x0, int y0, int x1, int y1, t_data *data);
void	draw_line_low(int x0, int y0, int x1, int y1, t_data *data);
void	draw_line_high(int x0, int y0, int x1, int y1, t_data *data);
/*
**	WINDOW
*/
void				window_setup(t_data *data);
int					key_press(int keycode, void *param);
/*
**	UTILS
*/
void				error(int n);
void				print_double_tab_int(int **tab); //TO BE REMOVE
int					tab_len(char **tab);
#endif
