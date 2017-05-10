/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_intarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 12:02:56 by wfung             #+#    #+#             */
/*   Updated: 2017/05/09 18:58:49 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_intarray(t_fdfstore *grid)
{
	int		i;
	int		j;

	i = 0;
	printf("start print_intarray\n");
	while (grid->array[i] != NULL)
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
	if (grid->array[i] == NULL)
		printf("it null bruh\n");
}

void		ft_make_intarray(t_fdfstore *grid)
{
	int			i;
	int			j;
	t_fdfstore	*buff;
	char		**result;

	i = 0;
	buff = grid;
	printf("grid->row = %i col = %i\n", grid->row, grid->col);
	if (!(grid->array = (int**)malloc(sizeof(int*) * (grid->row + 1))))
		return ;
	grid->array[grid->row] = NULL;
	printf("heyyyy\n");
	if (!(grid->array[i] = (int*)malloc(sizeof(int) * (grid->col + 1))))
		return ;
	while (grid->array[i] && i < grid->row)	//doesnt event go here
	{
		j = 0;
		printf("j while reset j = %i\n", j);
		result = ft_strsplit(buff->store, '	');
		while (j < grid->col)
		{
			grid->array[i][j] = ft_atoi(result[j]);
		//	buff = buff->next;
			printf("result [%i] = [%i]\n", j, ft_atoi(result[j]));
			printf("buff[%i][%i] created [%i]\n", i, j, ft_atoi(result[j]));
			j++;
		}
		buff = buff->next;
		printf("i while = %i\n", i);
		i++;
		if (!(grid->array[i] = (int*)malloc(sizeof(int) * (grid->col + 1))))
		{
			while (i > -2 && i--)
			{
				printf("free buff->array = %i\n", i + 1);
				free(grid->array[i + 1]);
			}
		}
	}
	printf("end while make_intarray\n");
}
