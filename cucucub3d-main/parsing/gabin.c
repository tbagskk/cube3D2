/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gabin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <gcherqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:05:23 by gcherqui          #+#    #+#             */
/*   Updated: 2023/05/23 15:05:23 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"


void	jsp(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			printf("%c ", map[i][j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
}

int	ft_strrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_strrdup(char **s1)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * (ft_strrlen(s1) + 1));
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = ft_strdup(s1[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	print_tab(int *tab_x, int *tab_y)
{
	int	i;

	while (tab_x[i])
	{
		printf("%d;", tab_x[i]);
		printf("%d", tab_y[i]);
		printf("\n");
		i++;
	}
}

int	verif_finish_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	search_begin(char **map, t_coordinate *coordinate)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
			{
				coordinate->x = i;
				coordinate->y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	find_map_dimensions(char **map, t_size *size)
{
	int	i;
	int	length;

	i = 0;
	size->height = 0;
	size->width = 0;
	while (map[i] != NULL)
	{
		length = ft_strlen(map[i]);
		if (length > size->width)
			size->width = length;
		i++;
	}
	size->height = i;
}

void	init_contour(char ***new_map, t_size *size)
{
	int	i;

	size->height += 2;
	size->width += 1;
	i = 0;
	*new_map = malloc(sizeof(char *) * (size->height + 1));
	while (i < size->height)
	{
		(*new_map)[i] = malloc(sizeof(char) * (size->width + 1));
		i++;
	}
	size->k = 0;
	size->l = 0;
}

char	**contour(char **map, t_size *size)
{
	int		i;
	int		j;
	char	**new_map;

	size->i = 0;
	init_contour(&new_map, size);
	while (size->i < size->height)
	{
		size->j = 0;
		size->l = 0;
		while (size->j < size->width)
			contour_all(new_map, size, map);
		new_map[size->i][size->width] = '\0';
		if (size->i > 0)
			size->k++;
		size->i++;
	}
	new_map[size->height] = NULL;
	return (new_map);
}



char	**replace(char **map, t_size *size)
{
	int	i;
	int	j;
	int max;

	i = 0;
	while (i < size->height ) /* quand on met -1 ca segfault plus pour les grand tab*/
	{
		j = 0;
		max = ft_strlen(map[i]);
		while (j < (max - 1))
		{
			if (!(map[i][j] && (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'N')))
				map[i][j] = '#';
			j++;
		}
		i++;
	}
	return (map);
}

char	**replace2(char **map)
{
	int i;
	int j;

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
	int i;
	int j;

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
	int max;

	max = (size->height * size->height * size->height);
	return (max);
}

int	deep_algo(t_cube *cube, t_size *size, t_coordinate *coordinate, int nb)
{
	int i;
	int j;
	int k;

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