/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_floatarray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:54:37 by wfung             #+#    #+#             */
/*   Updated: 2017/05/23 14:24:11 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_floatarray(t_fdfstore *grid)
{
	int		i;
	int		j;

	i = 0;
	printf("start print_floatarray\n");
	while (i < grid->row)
	{
		j = 0;
		while (j < grid->col)		//doesn't prfloat result of atoi 
		{					//WORKS WHEN j<grid->col but not while grid->array[i][j]
	/*		if (grid->f_array[i][j] < 10 || grid->f_array[i][j + 1] < 10)
				printf("[%f]", grid->f_array[i][j]);
			else
	*/			printf("[%f]", grid->f_array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
//	if (grid->f_array[i] == NULL)	//not needed?
//		printf("it null bruh\n");
}

void		ft_make_floatarray(t_fdfstore *grid)
{
	int			i;		//indices can only be ints in C
	int			j;
	t_fdfstore	*buff;
	char		**result;

	i = 0;
	buff = grid;
	printf("grid->row = %i col = %i\n", grid->row, grid->col);
	if (!(grid->f_array = (float**)malloc(sizeof(float*) * (grid->row + 1))))
		return ;
	grid->f_array[grid->row] = NULL;
	printf("heyyyy\n");
	if (!(grid->f_array[i] = (float*)malloc(sizeof(float) * (grid->col))))
		return ;
//	grid->f_array[grid->col] = NULL;	not needed because its a float not a ptr
	while (grid->f_array[i] && i < grid->row)	//doesnt event go here
	{
		j = 0;
		printf("j while reset j = %i\n", j);
		result = ft_strsplit(buff->store, '	');
		while (j < grid->col)
		{
			grid->f_array[i][j] = ft_atoi(result[j]);
		//	buff = buff->next;
		//	printf("result [%i] = [%i]\n", j, ft_atoi(result[j]));
			printf("atoi result [%i]\ngrid->f_array[%i][%i] = [%f]\n", ft_atoi(result[j]), i, j, grid->f_array[i][j]);
			j++;
		}
		buff = buff->next;
		printf("/////////////////////i while = %i\n", i);
		i++;
		if (!(grid->f_array[i] = (float*)malloc(sizeof(float) * (grid->col + 1))))
		{
	/*		while (i > -2 && i--)
			{
				printf("free buff->f_array = %i\n", i + 1);
				free(grid->f_array[i + 1]);
			}
	*/		return ;
		}
		grid->f_array[grid->col] = NULL;
	}
	printf("end while make_floatarray\n-------------------------\n");
}
