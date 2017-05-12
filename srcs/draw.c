/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:00:03 by wfung             #+#    #+#             */
/*   Updated: 2017/05/11 16:29:10 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(void *mlx, void *win, t_fdfstore *grid)
{
	int		i;
	int		j;

	i = 0;
	while (grid->array[i])
	{
		j = 0;
		while (j < grid->col)
		{
			if (i + 1 < grid->col)
				k++;
			if (j + 1 < grid->row)
				k++;
			if (
			j++;
		}
		i++;
	}
}
