/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:39:23 by wfung             #+#    #+#             */
/*   Updated: 2017/04/26 20:32:35 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_grid(char **grid)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (grid[i] != 0)
	{
		while (grid[i][j] != 0)
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
		*str++;
	}
	return (count);
}

t_fdfstore	make_grid(char **file)
{
	char	**grid;
	char	**buff;
	char	*fdfstr;
	char	*head;
	int		fd;

	fd = open(&file, O_RDONLY);
	while (get_next_line(fd, &buff) == 1)
	{
		if (fdfstr == NULL)
		{
			head = fdfstr;
			fdfstr = buff;
		}
		fdfstr = ft_strcat(fdfstr, buff);
		free(buff);
	}
	grid = ft_strsplit(fdfstr, '\n');
	ft_bzero(fdfstr);
	free(head);
	return (grid);
}
