/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:41:54 by vifonne           #+#    #+#             */
/*   Updated: 2019/02/12 04:07:27 by vifonne          ###   ########.fr       */
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
	int				offset;
	void			*mlx_ptr;
	void			*win;
	t_list			*raw_input;
}					t_data;
typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;
/*
**	PARSER
*/
void				read_stdin(t_data *data, char *filename);
void				parsing(t_data *data);
char				**split_fdf(char *str);
/*
**	DRAWING FUNCTIONS
*/
void	draw_line(t_point ps, t_point pe, t_data *data);
void	draw_default_line(int x0, int y0, int x1, int y1, t_data *data);
void	draw_vert_line(int x0, int y0, int y1, t_data *data);
//void	draw_line_low(int x0, int y0, int x1, int y1, t_data *data);
//void	draw_line_high(int x0, int y0, int x1, int y1, t_data *data);
void	draw_map(t_data *data);

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
int					itab_len(int **tab);
#endif
