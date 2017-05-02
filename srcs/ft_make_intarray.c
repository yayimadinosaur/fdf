/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_intarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 12:02:56 by wfung             #+#    #+#             */
/*   Updated: 2017/05/02 12:33:30 by wfung            ###   ########.fr       */
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
	if (!(buff->array = (int**)malloc(sizeof(int*) * (grid->row + 1))))
		return ;
	buff->array[grid->row] = NULL;
	printf("heyyyy\n");
	while (buff->array[i])	//doesnt event go here
	{
		j = 0;
		while (j < buff->col)
		{
			if (!(buff->array[i] = (int*)malloc(sizeof(int) * (buff->col + 1))))
			{
				while (i > -2 && i--)
					free(buff->array[i + 1]);
			}
			buff->array[buff->col] = NULL;
			buff->array[i][j] = ft_atoi(buff->store);
			buff = buff->next;
			j++;
		}
		i++;
	}
	printf("end while make_intarray\n");
}
