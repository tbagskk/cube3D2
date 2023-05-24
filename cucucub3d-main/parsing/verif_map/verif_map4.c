/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <gcherqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:38:15 by gcherqui          #+#    #+#             */
/*   Updated: 2023/05/24 18:39:30 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

void	delete_n(t_size *size)
{
	int	i;
	int	j;

	i = 0;
	while (size->map[i])
	{
		j = 0;
		while (size->map[i][j])
		{
			if (size->map[i][j] == 'N')
			{
				if (size->map[i][j + 1] == '#' || size->map[i][j - 1] == '#'
					|| size->map[i - 1][j] == '#'
						|| size->map[i + 1][j] == '#' )
					size->map[i][j] = 'G';
				else
					size->map[i][j] = '1';
			}
			j++;
		}
		i++;
	}
}

void	continue_deep2(t_cube *cube, t_size *size,
	t_coordinate *coordinate, int zero)
{
	if (zero == 1)
		deep_algo(cube, size, coordinate, 1);
	else
	{
		if (search_g(size->map) == -1)
			printf("ERROR -> MAP OUVERTE\n");
		jsp(size->map);
	}
}

void	continue_deep(t_size *size, t_cube *cube, t_coordinate *coordinate)
{
	int	i;
	int	j;
	int	zero;

	delete_n(size);
	i = 0;
	zero = 0;
	while (size->map[i] && zero == 0)
	{
		j = 0;
		while (size->map[i][j])
		{
			if (size->map[i][j] == '0')
			{
				size->map[i][j] = 'N';
				zero = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	continue_deep2(cube, size, coordinate, zero);
}
