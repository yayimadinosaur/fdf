/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_intarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 12:02:56 by wfung             #+#    #+#             */
/*   Updated: 2017/05/01 20:04:53 by wfung            ###   ########.fr       */
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

	i = 0;
	buff = grid;
	printf("hey\n");
	if (!(grid->array = (int**)malloc(sizeof(int*) * (grid->row + 1))))
		return ;
	grid->array[grid->col] = NULL;
	printf("heyyyy\n");
	while (grid->array[i])	//doesnt event go here
	{
		j = 0;
		while (buff)
		{
			if (!(buff->array[i] = (int*)malloc(sizeof(int) * (buff->col + 1))))
			{
				while (i > -2 && i--)
					free(buff->array[i + 1]);
			}
			buff->array[buff->row] = NULL;
			buff->array[i][j] = ft_atoi(buff->store);
			printf("ft_make_intarray j = %i\n", j);
			j++;
		}
		printf("ft_make_intarray i = %i\n", i);
		buff = buff->next;
		i++;
	}
}
