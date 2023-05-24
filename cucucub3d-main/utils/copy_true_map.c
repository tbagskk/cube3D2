/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_true_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <gcherqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:43:02 by gcherqui          #+#    #+#             */
/*   Updated: 2023/05/24 18:44:52 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

// copy_true_map //

// copy the .cub but only the map //

int	max_true_map(char **map, int start)
{
	int	y;
	int	j;
	int	max;

	y = 0;
	max = 0;
	while (map[start + y])
	{
		j = 0;
		while (map[start + y][j])
		{
			if (j > max)
				max = j;
			j++;
		}
		y++;
	}
	max += 2;
	return (max);
}

void	copy_true_map3(char **true_map, int *j, int max, int *y)
{
	(*j)--;
	while (*j < (max - 1))
	{
		true_map[*y][*j] = ' ';
		(*j)++;
	}
	true_map[*y][*j] = '\0';
	(*y)++;
}

void	copy_true_map2(char **map, char **true_map, int start, int max)
{
	int	y;
	int	k;
	int	j;

	y = 0;
	while (map[start + y])
	{
		true_map[y] = malloc(sizeof(char) * (max + 1));
		k = 0;
		j = 0;
		while (map[start + y][k] != '\0' && j < (max - 1))
		{
			true_map[y][j] = map[start + y][k];
			k++;
			j++;
		}
		copy_true_map3(true_map, &j, max, &y);
	}
	true_map[y] = NULL;
}

char	**copy_true_map(char **map)
{
	char	**true_map;
	int		start;
	int		y;
	int		max;

	max = 0;
	start = begining_map(map);
	true_map = NULL;
	y = 0;
	while (map[start + y])
		y++;
	true_map = malloc(sizeof(char *) * (y + 1));
	max = max_true_map(map, start);
	copy_true_map2(map, true_map, start, max);
	return (true_map);
}
