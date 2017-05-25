/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:34:08 by wfung             #+#    #+#             */
/*   Updated: 2017/05/25 15:12:58 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

/*
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
*/

/*
void	draw(void *mlx, void *win, t_fdfstore *grid)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	while (grid->str[i])
	{
		while (grid->str[i][j])
		{
			if (j + 1 < grid->row_max && grid->str[i][j] != ' ')
			{
				if (grid->str[i][j + 1] != ' ')
				{
					tmp = i;
					while (tmp < i + 300)
					{
						mlx_pixel_put(mlx, win, tmp, j + 150, 0xffffff);
						tmp = tmp + 10;
					}
				}
				mlx_pixel_put(mlx, win, i, j, 0xffffff);
			}
			if (i + 1 < grid->col_max && grid->str[i][j] != ' ')
			{
				if (grid->str[i + 1][j] != ' ')
				{
					tmp = j;
					while (tmp < j + 300)
					{
						mlx_pixel_put(mlx, win, i + 150, tmp, 0xffffff);
						tmp = tmp + 10;
					}
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
}
*/

/*
int		expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}
*/

/*draw w/ 5 variables*/
void	draw(void *mlx, void *win, t_fdfstore *grid)
{
	int		i;
	int		j;
	int		n;	//stopper? for y?
	int		p;	//stopper for x?
	int		m;	//slope
//	int		x;	//old

	i = 0;
	printf("grid value test col %i row %i win_x %f win_y %f center_x %f center_y %f start_x %f start_y %f\n", grid->col, grid->row, grid->win_x, grid->win_y, grid->center_x, grid->center_y, grid->start_x, grid->start_y);
	while (i < grid->col)	//remember to print proper array	//old - while(grid->f_array[i]
	{
		j = 0;
		while (j < grid->row)
		{
			m = ((j - (j + 1)) / (i - (i + 1))) * j + 1;
		//	n = grid->start_x + (grid->win_x / (grid->col * j + 1));
		//	p =  grid->start_y + (grid->win_y / (grid->row * i + 1));
			n = grid->start_x + grid->start_x * i;
			p = grid->start_y + grid->start_y * j;
			printf("j = [%i] i = [%i] m = [%i] n = [%i] p = [%i]\n", j, i, m, n, p);
			while (n > grid->start_x + grid->start_x * (i - 1))
			{
			//	mlx_pixel_put(mlx, win, n * m + n , p, 0xff00);	//green
			//	mlx_pixel_put(mlx, win, n, p * m + p, 0xffff00);	//yellow
				mlx_pixel_put(mlx, win, n, p, 0xff);	//blue	//was - red
			//	mlx_pixel_put(mlx, win, n * m + n, p * m + p, 0xffffff);	//white
				n--;
			printf("n now = [%i] p now = [%i]\n", n, p);
			}
			while (p > grid->start_y + grid->start_y * (j - 1))
			{
				mlx_pixel_put(mlx, win, n, p, 0xff0000);	//red
				p--;
			}
/*
		j = 0;
		while (j < grid->col)	//grid->f_array[i][j] fails printing
		{
			x = 50;
			if (i + 1 < grid->row)
			{
				n = grid->start_x + ((grid->win_x / grid->col) * i);
				printf("n = [%i]\n", n);
				while (x > 1 && x--)
					mlx_pixel_put(mlx, win, grid->start_y + n, grid->start_x + (x * n) + 1, 0xff00);	//green
				while (n > 0 && n--)
					mlx_pixel_put(mlx, win, grid->start_y + (n * i), grid->start_x, 0xffffff);	//print outside x white
			}
			x = 50;
			if (j + 1 < grid->col)
			{
				p = grid->start_y + (grid->win_y / grid->row) + 1;
				printf("p = [%i]\n", p);
				while (x > 1 && x--)
					mlx_pixel_put(mlx, win, grid->start_y + (x * p) + 1, grid->start_x + p + x, 0xffff00);	//yellow
				while (p > 0 && p--)
					mlx_pixel_put(mlx, win, grid->start_y, grid->start_x + (p * j), 0xff0000);	//print outside y red
					}
*/

			//	printf("value chk %i, %i, %i, %i, %i, %i\n", grid->win_x, grid->win_y, grid->center_x, grid->center_y, grid->start_x, grid->start_y);
	//		if (i + 1 < grid->row && j + 1 < grid->col)
	//		{
	//			n = grid->start_x + (grid->win_x / grid->col) + 1;
	//			while (n > 0 && n--)
	//				mlx_pixel_put(mlx, win, grid->start_y + (n * i), grid->start_x + (n * i), 0xff00);	//green
	//			p = grid->start_y + (grid->win_y / grid->row) + 1;
	//			while (p > 0 && p--)
	//				mlx_pixel_put(mlx, win, grid->start_y + (p * j), grid->start_x + (p * j), 0xffff00);	//yellow
	//		}
		//	if (grid->f_array[i][j] == grid->f_array[i + 1][j] && grid->f_array[i][j + 1])
		//	{
//
//			}
	//		printf("i = %i j = %i [%f]\n", i, j, grid->f_array[i][j]);
			j++;
		}
		i++;
	}
	printf("fin draw ft\n");
}


/*draw 3 
void	draw(void *mlx, void *win, t_fdfstore *grid)
{
	float	x;
	float	y;

	x = grid->start_x;
	while (x < grid->win_x - grid->start_x)
	{
		y = grid->start_y;
		while (y < grid->win_y - grid->start_y)
		{
			if ((y >= grid->start_y && y <= grid->start_y + 50) && (x >= grid->start_x && x <= grid->start_x + 50))
				mlx_pixel_put(mlx, win, y, x, 0xff00);	//green
	//		if (y >= grid->start_y && x < grid->start_x)
	//			mlx_pixel_put(mlx, win, y, x, 0xffff00);	//yellow
			y++;
		}
		x++;
	}
}
*/

int		mouse_hook(int button, int x, int y, t_env *e)
{
	t_env w;

	w = *e;
	printf("mouse: %d (%d:%d)\n", button, x, y);
	mlx_pixel_put(e->mlx, e->win, x, y, 0xff0000);
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

void	set_window(int n, t_fdfstore *grid)
{
	if (n < 0)
		ft_putstr("window size needs to be positive\n");
	if (n == 0)
		ft_putstr("window size needs to be greater than 0\n");
	grid->win_x = n;
	grid->win_y = n;
	grid->center_x = n / 2;
	grid->center_y = n / 2;
	grid->start_x = (n - ( n / 10)) / grid->col;		//starts off 10% inside x y
	grid->start_y = (n - ( n / 10)) / grid->row;
}

int		main(int ac, char **av)
{
	t_env		e;
	t_fdfstore	*grid;
	int			fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!(grid = (t_fdfstore*)malloc(sizeof(t_fdfstore) * (1))))
			return (0);
		grid->next = NULL;
		if (make_grid(fd, grid) == 0)
		{
			printf("make grid fails\n");
//			clr_struct(grid);
			return (0);
		}
		ft_make_floatarray(grid);
		print_floatarray(grid);	//for testing purposes
		set_window(600, grid);	//set window values
		e.mlx = mlx_init();		//fails if returns NULL PTR
		e.win = mlx_new_window(e.mlx, grid->win_x, grid->win_y, "42");	//creates new window
		draw(e.mlx, e.win, grid);
//		mlx_key_hook(e.win, key_hook, &e);
//	if (mlx_key_hook(e.win, key_hook, &e) == 53)
//		return (0);
//	mlx_expose_hook(e.win, expose_hook, &e);
	//	mlx_mouse_hook(e.win, mouse_hook, &e);		//MOUSE HOOK PRINTS PIXEL AT MOUSE LOCATION!
//	mlx_mouse_hook(e.win, draw_mouse, &e);
		mlx_loop(e.mlx);	//function never returns / infinite loop
//	mlx_clear_window(e.mlx, e.win);	//clears window	
	//	sleep(5);
	//	usleep(5000);
	}
	else
		write(1, "Not Enough Args\n", 16); 
	return (0);
}
