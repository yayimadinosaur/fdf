/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:34:08 by wfung             #+#    #+#             */
/*   Updated: 2017/04/27 17:51:22 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
typedef struct	s_env
{
	void *mlx;
	void *win;
}				t_env;


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
*

void	draw(void *mlx, void *win)
{
	int		x;
	int		y;
	int		j;	//random variable to compare to

	j = 50;
	y = 50;
	while (y < 301)
	{
		x = 50;
		while (x < 501)
		{
//			if (x == 50 || y == 50 || x == 299 || y == 299)
//				mlx_pixel_put(mlx, win, x, y, 0xAAAAAAA);	//border hardcoded
			if (x % 25 == 0 || y % 25 == 0)			//border w %
			//	mlx_pixel_put(mlx, win, x, y, 0xCCCC00D); //yellow
				mlx_pixel_put(mlx, win, x, y, 0xAAAAAAA);
			if (((x == 100 || x == 125) && y >= 100 && y <= 175)
						|| (x >= 100 && x <= 125 && (y == 100
						|| y == 125 || y == 150 || y == 175)))
				mlx_pixel_put(mlx, win, x, y, 0xff00ff);
			if (x >= 100 && x <= 225 && x == y)
			{
				mlx_pixel_put(mlx, win, x, y, 0xff00ff);	
				j++;
				//drew diagonal lines down righ
			}
			//^ magenta left side of 4
			if (x > 225 && x <= 300 && y >= 225 && y <= 300 && ( y < x))
				mlx_pixel_put(mlx, win, x, y, 0x2e8b57);
			if (x > 300 && x <= 350 && y > 100 && y < 150)
				mlx_pixel_put(mlx, win, x, y, 0xffa500);

	*
	 *	hardcoded 42 in white
	 * 		if (x >= 100 && x <= 150 && y >= 100 && y <= 200) 
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
	*		x = x + 1;
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

*/
int		main(int ac, char **av)
{
//	t_env		e;
	t_fdfstore	*grid;
	int			fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!(grid = (t_fdfstore*)malloc(sizeof(t_fdfstore) * (1))))
			return (0);
		grid->str = make_grid(fd);
		print_grid(grid->str);
/*		e.mlx = mlx_init();		//fails if returns NULL PTR
		e.win = mlx_new_window(e.mlx, 550, 400, "42");	//creates new window
		draw(e.mlx, e.win);
		mlx_key_hook(e.win, key_hook, &e);
//	if (mlx_key_hook(e.win, key_hook, &e) == 53)
//		return (0);
//	mlx_expose_hook(e.win, expose_hook, &e);
		mlx_mouse_hook(e.win, mouse_hook, &e);
//	mlx_mouse_hook(e.win, draw_mouse, &e);
		mlx_loop(e.mlx);	//function never returns / infinite loop
//	mlx_clear_window(e.mlx, e.win);	//clears window	
		sleep(5);
		usleep(5000);
*/	}
	return (0);
}
