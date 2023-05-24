/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <gcherqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:40:02 by gcherqui          #+#    #+#             */
/*   Updated: 2023/05/24 18:40:24 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

char	**replace2(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
	return (map);
}

int	search_g(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'G')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_all_size(t_size *size)
{
	free(size->tab_x);
	free(size->tab_y);
	freel(size->map, size->height);
}

int	max_nb(t_size *size)
{
	int	max;

	max = (size->height * size->height * size->height);
	return (max);
}

int	deep_algo(t_cube *cube, t_size *size, t_coordinate *coordinate, int nb)
{
	int	i;
	int	j;
	int	k;

	init_deep(&k, &i, &j);
	init_deep_algo(size, cube, coordinate, nb);
	init_deep_algo2(coordinate, &i, &j, size);
	size->cmp = max_nb(size);
	while (size->cmp--)
	{
		deep_algo2(&i, &j, &k, size);
		if (k < 0)
			break ;
		size->tab_x[k] = i;
		size->tab_y[k] = j;
	}
	continue_deep(size, cube, coordinate);
	return (0);
}
