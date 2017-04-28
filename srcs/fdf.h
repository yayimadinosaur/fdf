/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:06:47 by wfung             #+#    #+#             */
/*   Updated: 2017/04/27 17:53:50 by wfung            ###   ########.fr       */
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

typedef struct			s_env
{
	void				*mlx;
	void				*win;
}						t_env;

typedef struct			s_fdfstore
{
	char				**str;
	struct s_fdfstore	*next;
	int					x;
	int					y;
	int					z;
}						t_fdfstore;

char	**make_grid(int fd);
int		count_chr(char *str, int n);
void	print_grid(char **grid);

#endif
