/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <gcherqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:36:29 by gcherqui          #+#    #+#             */
/*   Updated: 2023/05/24 18:37:23 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

void	contour2(char ***new_map, t_size *size)
{
	char	symbole;
	int		i;
	int		j;

	symbole = '#';
	i = size->i;
	j = size->j;
	if (i == 0)
		(*new_map)[i][j] = symbole;
	else if (i == size->height - 1)
		(*new_map)[i][j] = symbole;
	else if (j == 0 || j == size->width - 1)
		(*new_map)[i][j] = symbole;
}

//fonction avec trop d'argument
void	contour3(char ***new_map, t_size *size, char **map)
{
	int	i;
	int	j;

	i = size->i;
	j = size->j;
	if (size->k < size->height - 2 && size->l < size->width - 1)
	{
		(*new_map)[i][j] = map[size->k][size->l];
		size->l++;
	}
	else
		(*new_map)[i][j] = ' ';
}

void	contour_all(char **new_map, t_size *size, char **map)
{
	int	i;
	int	j;

	i = size->i;
	j = size->j;
	if (i == 0 || i == size->height - 1 || j == 0 || j == size->width - 1)
		contour2(&new_map, size);
	else
		contour3(&new_map, size, map);
	size->j++;
}

void	init_deep(int *k, int *i, int *j)
{
	*k = 1;
	*i = 0;
	*j = 0;
}

void	deep_algo2(int *i, int *j, int *k, t_size *size)
{
	if (size->map[*i][*j + 1] == '0')
		vrf_map(j, k, i, size, 1);
	else if (size->map[*i][*j - 1] == '0')
		vrf_map(j, k, i, size, 1);
	else if ((*i + 1 <= size->height) && size->map[*i + 1][*j] == '0')
		vrf_map(j, k, i, size, 1);
	else if ((*i - 1 >= 0) && size->map[*i - 1][*j] == '0')
		vrf_map(j, k, i, size, 1);
	else
		vrf_map(j, k, i, size, 0);
}
