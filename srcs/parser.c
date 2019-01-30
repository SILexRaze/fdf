/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:51:32 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/30 12:39:00 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_stdin(t_data *data, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_list_pushback(&data->raw_input, ft_strdup(line), 0);
			ft_strdel(&line);
		}
		close (fd);
	}
	else
		error(-2);
}

void	parsing(t_data *data)
{
	int		i;
	int		x;
	int		y;
	t_list	*tmp;
	char	**tmp_tab;

	tmp = data->raw_input;
	if (!(data->tab = (int **)ft_memalloc(sizeof(int *) * ft_list_size(&tmp) + 1)))
		exit(0);
	y = 0;
	while (tmp)
	{
		tmp_tab = split_fdf(tmp->data);
		i = 0;
		x = 1;
		data->tab[y] = (int *)ft_memalloc(sizeof(int) * tab_len(tmp_tab) + 1);
		while (tmp_tab[i])
		{
			if (!ft_strstr(tmp_tab[i], "0x"))
			{
				data->tab[y][x] = ft_atoi(tmp_tab[i]);
				x++;
			}
			i++;
		}
		data->tab[y][0] = x;
		y++;
		tmp = tmp->next;
	}
	data->tab[y] = NULL;
}
