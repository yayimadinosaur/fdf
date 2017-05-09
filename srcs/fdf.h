/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:06:47 by wfung             #+#    #+#             */
/*   Updated: 2017/05/08 16:48:16 by wfung            ###   ########.fr       */
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
	char					*store;
	char					**strsplit_result;
	int						**array;
	struct s_fdfstore		*next;
	int						x;
	int						y;
	int						z;
	int						col;
	int						row;
}							t_fdfstore;

void	ft_make_intarray(t_fdfstore *grid);
void	print_intarray(t_fdfstore *grid);
int		make_grid(int fd, t_fdfstore *grid);
int		count_chr(char *str, int n, int stop);
void	print_grid(char **grid);

#endif
