/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:39:23 by wfung             #+#    #+#             */
/*   Updated: 2017/04/30 19:55:25 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**make_intarray(char *str, t_fdfstore grid, int row_max, int col_max)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i] = ' ' || str[i] = '\0')
				j++;
		}
		i++;
	}
	return (buff);
}

void	print_grid(char **grid)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (grid[i])
	{
		while (grid[i][j])
		{
			printf("%c", grid[i][j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
}


int		count_chr(char *str, int n, int stop)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i] != stop)
	{
		if (str[i] == (char)n)
			count++;
		i++;
	}
	return (count);
}


int		make_grid(int fd, t_fdfstore *grid)
{
	char	tmp[BUFF_SIZE + 1];
	char	*buff;
	char	*hold;
	int		count;

	buff = NULL;
	hold = NULL;
	while ((count = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[count] = '\0';
		if (buff == NULL)
			buff = ft_strdup(tmp);
		else
		{
			hold = ft_strjoin(buff, tmp);
			free(buff);
			buff = hold;
		}
	}
/*	grid->row_max = count_chr(buff, '\n', '\0');
	printf("row_max = %i\n", grid->row_max);
	grid->col_max = count_chr(buff, ' ', '\n');
	printf("col_max = %i\n", grid->col_max);
*/	if (!(grid->str = ft_strsplit(buff, '\n')))
		return (0);
	free(hold);
	return (1);
}
