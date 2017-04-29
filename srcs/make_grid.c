/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:39:23 by wfung             #+#    #+#             */
/*   Updated: 2017/04/28 19:48:57 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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


int		count_chr(char *str, int n)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (*str == n)
			count++;
		str++;
	}
	return (count);
}


char	**make_grid(int fd)
{
	char	tmp[BUFF_SIZE + 1];
	char	*buff;
	char	*hold;
	char	**array;
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
	array = ft_strsplit(buff, '\n');
	free(hold);
	return (array);
}
