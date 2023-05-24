/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <gcherqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:34:36 by gcherqui          #+#    #+#             */
/*   Updated: 2023/05/24 18:35:58 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Cub3D.h"

void	freel(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	vrf_map2(int *j, int *k, int *i, t_size *size)
{
	if (size->map[*i][*j] == 'x' && (size->map[*i][*j + 1] == '#'
			|| size->map[*i][*j - 1] == '#' || size->map[*i - 1][*j] == '#'
			|| size->map[*i + 1][*j] == '#'))
		size->map[*i][*j] = 'G';
	--*k;
	if (*k > 0)
	{
		//*i = size->tab_x[*k];
		//*j = size->tab_y[*k];
		;
	}
}

void	vrf_map(int *j, int *k, int *i, t_size *size, int nb)
{
	if (nb == 1)
	{
		if (size->map[*i][*j + 1] == '0')
			++*j;
		else if (size->map[*i][*j - 1] == '0')
			--*j;
		else if ((*i + 1 <= size->height) && size->map[*i + 1][*j] == '0')
			++*i;
		else if ((*i - 1 >= 0) && size->map[*i - 1][*j] == '0')
			--*i;
		size->map[*i][*j] = 'x';
		++*k;
	}
	else
		vrf_map2(j, k, i, size);
}

void	init_deep_algo(t_size *size, t_cube *cube,
	t_coordinate *coordinate, int nb)
{
	char	**mapp;
	char	**mapp2;

	if (nb == 0)
	{
		mapp = ft_strrdup(cube->true_map);
		search_begin(mapp, coordinate);
		find_map_dimensions(mapp, size);
		size->tab_x = malloc(sizeof(int) * (pow(size->height, 3)));
		size->tab_y = malloc(sizeof(int) * (pow(size->width, 3)));
		replace(mapp, size);
		mapp2 = contour(mapp, size);
		size->map = ft_strrdup(mapp2);
		freel(mapp2, size->height);
		freel(mapp, (size->height - 2));
	}
}

void	init_deep_algo2(t_coordinate *coordinate, int *i, int *j, t_size *size)
{
	search_begin(size->map, coordinate);
	*i = coordinate->x;
	*j = coordinate->y;
	size->tab_x[0] = *i;
	size->tab_y[0] = *j;
}
