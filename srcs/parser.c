/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:51:32 by vifonne           #+#    #+#             */
/*   Updated: 2019/04/22 17:46:59 by vifonne          ###   ########.fr       */
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

static void	raw_to_tab(t_data *data, char **tmp_tab, t_point *p)
{
	int	i;

	i = 0;
	p->x = 1;
	data->tab[p->y] = (int *)ft_memalloc(sizeof(int) * tab_len(tmp_tab) + 1);
	while (tmp_tab[i])
	{
		if (!ft_strstr(tmp_tab[i], "0x"))
		{
			data->tab[p->y][p->x] = ft_atoi(tmp_tab[i]);
			p->x++;
		}
		i++;
	}
	data->tab[p->y][0] = p->x;
	p->y++;
}

void	parsing(t_data *data)
{
	t_point	p;
	t_list	*tmp;
	char	**tmp_tab;

	tmp = data->raw_input;
	if (!(data->tab = (int **)ft_memalloc(sizeof(int *) * ft_list_size(&tmp) + 1)))
		exit(0);
	p.y = 0;
	while (tmp)
	{
		tmp_tab = split_fdf(tmp->data);
		raw_to_tab(data, tmp_tab, &p);
		tmp = tmp->next;
	}
	data->tab[p.y] = NULL;
}
