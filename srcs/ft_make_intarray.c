/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_intarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 12:02:56 by wfung             #+#    #+#             */
/*   Updated: 2017/05/01 19:25:41 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_intarray(t_fdfstore *grid)
{
	int		i;
	int		j;

	i = 0;
	while (grid->array[i])
	{
		j = 0;
		while (grid->array[i][j])
		{	
			printf("[%i]", grid->array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void		ft_make_intarray(t_fdfstore *grid)
{
	int			i;
	int			j;
	t_fdfstore	*buff;

	i = 0;
	buff = grid;
	if (!(grid->array = (int**)malloc(sizeof(int*) * (grid->col + 1))))
		return ;
	grid->array[grid->col] = NULL;
	while (grid->array[i])
	{
		j = 0;
		while (buff)
		{
			if (!(buff->array[i] = (int*)malloc(sizeof(int) * (buff->row + 1))))
			{
				while (i > -2 && i--)
					free(buff->array[i + 1]);
			}
			buff->array[buff->row] = NULL;
			buff->array[i][j] = ft_atoi(buff->store);
			j++;
		}
		buff = buff->next;
		i++;
	}
}
