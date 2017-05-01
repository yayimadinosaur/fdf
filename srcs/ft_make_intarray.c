/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_intarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 12:02:56 by wfung             #+#    #+#             */
/*   Updated: 2017/05/01 12:27:22 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			**ft_fill_array(char **buff, int col, char *str, t_fdfstore grid)
{
	int		i;
	int		j;

	i = -1;
	while (str[i] != 0 && i++)
	{
		k = 0;
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-'))
		{
			buff[j][k] = str[i];
			k++;
		}
		if (str[j] == ' ')
			j++;
	}
	if (!(grid->int_array = (int**)malloc(sizeof(int*) * (col + 1))))
		return (NULL);
	return (buff);

}

char		**ft_create_buffarray(char **buff, int col, char *str)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	while (buff[i] != 0 && i++)
		ft_memalloc(buff[i], col);
	i = 0;
	while (buff[i] != 0)
	{
		while ((str[j] >= '0' && str[j] <= '9') || (str[j] == '-'
				&& str[j + 1] >= '0' && str[j + 1] <= 9))
			j++;
		if (str[j] == ' ' && (str[j + 1] >= '0' && str[j + 1] <= '9')
				|| str[j + 1] == '\0')
		{
			if (!(buff[i] = ft_memalloc(j)))
				return (NULL);
		}
		j = 0;
		i++;
	}
	return (buff);
}

int		**ft_make_intarray(char *str, t_fdfstore grid)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (*str)
	{
/*		if (*str >= '0' && *str <= '9' && (*str + 1 == ' ' || *str + 1 == '\0'))
			j++;		//counter increases at end of nums
*/		if (*str == '\n')
		{
			k++;
//			j = 0;
		}
		str++;
	}
	if (!(grid->strsplit_result = (char**)malloc(sizeof(char*) * (k + 1))))
		return (NULL);
	grid->strsplit_result[k + 1] = NULL;
	if (!(ft_create_buffarray(grid->strsplit_result, k, str)))
		return (NULL);
	if (!(ft_fill_array(grid->strsplit_result, k, str)))
		return (NULL);
	return (grid->int_array);
}
