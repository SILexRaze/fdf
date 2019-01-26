/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifonne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:22:06 by vifonne           #+#    #+#             */
/*   Updated: 2019/01/26 13:59:09 by vifonne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*img;
	void	*win;
	int		done;

	done = 1;
	mlx_ptr = mlx_init();
	win = mlx_new_window(mlx_ptr, 1920, 1080, "Test mlx");
	mlx_clear_window(mlx_ptr, win);
	img = mlx_new_image(mlx_ptr, 1920, 1080);
	if (win && img)
	{
		int	i = 0;
		while (i < 1920)
		{
			mlx_pixel_put(mlx_ptr, win, i, 10, 0xFFFFFF);
			i++;
		}
		mlx_string_put(mlx_ptr, win, 1920/2, 1080/2, 0xFFFFFF, "Hello World!");
		printf("OK\n");
	}
	else
		printf("Error\n");
	mlx_hook(win, 2, 0L, key_press, NULL);
	mlx_loop(mlx_ptr);
	return (0);
}
