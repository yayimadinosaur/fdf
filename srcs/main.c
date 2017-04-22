/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:34:08 by wfung             #+#    #+#             */
/*   Updated: 2017/04/21 21:33:45 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include <unistd.h>

typedef struct	s_env
{
	void *mlx;
	void *win;
}				t_env;

/*
int		draw_mouse(void *mlx, void *win, int button, int x, int y)
{
	printf("drawing %d x: %i y: %i\n", button, x, y);
	if (button == 1)
	{
	//	if (x > 100 && x < 200)
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
	//	else
	//		mlx_pixel_put(e->mlx, e->win, x, y, 0xFF000FF);
	}
	else if (button == 2)
	{
	//	if (x > 100 && x < 200)
			mlx_pixel_put(mlx, win, x, y, 0x00FFFF);
	//	else
	//		mlx_pixel_put(e->mlx, e->win, x, y, 0x0000011);
	}
	return (0);
}
*/

void	draw(void *mlx, void *win)
{
	int		x;
	int		y;

	y = 100;
	while (y < 300)
	{
		x = 100;
		while (x < 300)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFF);
			x = x + 7;
		}
		y = y + 7;
	}
}

int		expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	printf("mouse: %d (%d:%d)\n", button, x, y);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	printf("key: %d\n", keycode);
	if (keycode == 53)
		return (53);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "42");
	draw(e.mlx, e.win);
	mlx_key_hook(e.win, key_hook, &e);
//	if (mlx_key_hook(e.win, key_hook, &e) == 53)
//		return (0);
//	mlx_expo_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
//	mlx_mouse_hook(e.win, draw_mouse, &e);
	mlx_loop(e.mlx);
	//sleep(5);
	//usleep(5000);
	return (0);
}
