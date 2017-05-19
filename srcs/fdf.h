/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:06:47 by wfung             #+#    #+#             */
/*   Updated: 2017/05/19 14:27:30 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
# define __FDF_H__

#include <unistd.h> 
#include <stdlib.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

typedef struct				s_env
{
	void					*mlx;
	void					*win;
}							t_env;

typedef struct				s_fdfstore
{
	char					*store;			//??
	char					**strsplit_result;	//isnt used right now
	int						**array;
	float					**f_array;
	struct s_fdfstore		*next;
	int						x;
	int						y;
	int						z;		//find out how to use
	int						col;
	int						row;
	float					win_x;		//save max x axis of window
	float					win_y;		//save max y axis of window
	float					center_x;
	float					center_y;
	float					start_x;
	float					start_y;
}							t_fdfstore;

void	ft_make_intarray(t_fdfstore *grid);
void	ft_make_floatarray(t_fdfstore *grid);

void	print_intarray(t_fdfstore *grid);
void	print_floatarray(t_fdfstore *grid);

int		make_grid(int fd, t_fdfstore *grid);
int		count_chr(char *str, int n, int stop);
void	print_grid(char **grid);

void	set_window(int	n, t_fdfstore *grid);

#endif
