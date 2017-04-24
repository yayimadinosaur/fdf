/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:34:08 by wfung             #+#    #+#             */
/*   Updated: 2017/04/23 17:51:59 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include <unistd.h>

//	42 logo star wars color w/ dots at variable + 5
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
			mlx_pixel_put(mlx, win, x, y, 0x00AAAF);
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

	y = 50;
	while (y < 301)
	{
		x = 50;
		while (x < 501)
		{
//			if (x == 50 || y == 50 || x == 299 || y == 299)
//				mlx_pixel_put(mlx, win, x, y, 0xAAAAAAA);	//border hardcoded
			if (x % 25 == 0 || y % 25 == 0)			//border w %
				mlx_pixel_put(mlx, win, x, y, 0xCCCC00D); //white
			if (x >= 100 && x <= 150 && y >= 100 && y <= 200) 
				mlx_pixel_put(mlx, win, x, y, 0xAAAAAAA);
			if (x >= 200 && x <= 250 && y >= 100 && y <= 275)
				mlx_pixel_put(mlx, win, x, y, 0xAAAAAAA);
			if (x >= 150 && x <= 200 && y >= 175 && y < 225)
				mlx_pixel_put(mlx, win, x, y, 0xAAAAAAA);
			if (x >= 125 && x <= 150 && y >= 200 && y < 225)
				mlx_pixel_put(mlx, win, x, y, 0xAAAAAAA);
			if (x >= 300 && x <= 425 && y >= 100 && y < 125)
				mlx_pixel_put(mlx, win, x, y, 0xAAAAAAA);
			if (x >= 325 && x <= 425 && y >= 175 && y <= 200)
				mlx_pixel_put(mlx, win, x, y, 0xAAAAAAA);
			if (x >= 300 && x <= 450 && y >= 250 && y <= 275)
				mlx_pixel_put(mlx, win, x, y, 0xAAAAAAA);
			if (x >= 400 && x <= 450 && y >= 125 && y <= 175)
				mlx_pixel_put(mlx, win, x, y, 0xAAAAAAA);
			if (x >= 300 && x <= 350 && y >= 200 && y <= 250)
				mlx_pixel_put(mlx, win, x, y, 0xAAAAAAA);
			x = x + 1;
		}
		y = y + 1;
	}
}

int		expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	t_env w;

	w = *e;
	printf("mouse: %d (%d:%d)\n", button, x, y);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	t_env w;
	w = *e;
	printf("key: %d\n", keycode);
	if (keycode == 53)
		return (53);
	return (0);
}

int		main(void)
{
	t_env	e;

	e.mlx = mlx_init();		//fails if returns NULL PTR
	e.win = mlx_new_window(e.mlx, 550, 400, "42");	//creates new window
	draw(e.mlx, e.win);
	mlx_key_hook(e.win, key_hook, &e);
//	if (mlx_key_hook(e.win, key_hook, &e) == 53)
//		return (0);
//	mlx_expo_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
//	mlx_mouse_hook(e.win, draw_mouse, &e);
	mlx_loop(e.mlx);	//function never returns / infinite loop
//	mlx_clear_window(e.mlx, e.win);	//clears window	
	sleep(5);
	usleep(5000);
	return (0);
}

//	USUAL CALL ORDER
//	expo_hook(voi *param);
//	key_hook_(int keycode, void *param);
//	mouse_hook(int button, int x, int y, void *param);
//	loop_hook(void *param);
//
//	int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *str);
//
//	mlx_new_image
//		creates new image
//		user can draw into it
//	mlx_put_image_to_window
//		puts created image to window
