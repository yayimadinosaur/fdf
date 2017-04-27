/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:06:47 by wfung             #+#    #+#             */
/*   Updated: 2017/04/26 20:24:12 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
# define __FDF_H__

#include "libft/libft.h"
#include "mlx.h"

typedef struct			s_fdfstore
{
	char				**str;
	struct s_fdfstore	*next;
	int					x;
	int					y;
	int					z;
}						t_fdfstore;

char	**make_grid(char **file);
int		count_chr(char *str, int n);
void	print_grid(char **grid);

#endif
