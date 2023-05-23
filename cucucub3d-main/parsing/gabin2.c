
#include "../Cub3D.h"


void	freel(char **str, int n)
{
	int i;

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

void	init_deep_algo(t_size *size, t_cube *cube, t_coordinate *coordinate, int nb)
{
	char **mapp;
	char **mapp2;

	if (nb == 0)
	{
		mapp = ft_strrdup(cube->true_map);
		search_begin(mapp, coordinate);
		find_map_dimensions(mapp, size);
		size->tab_x = malloc(sizeof(int) * (pow(size->height, 3)));
		size->tab_y = malloc(sizeof(int) * (pow(size->width, 3)));
		replace(mapp, size);
		//mapp2 = contour(mapp, size);
		size->map = ft_strrdup(mapp);
		//freel(mapp2, size->height);
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

void	contour2(char ***new_map, t_size *size)
{
	char symbole;
	int i;
	int j;

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
	int i;
	int j;

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
	int i = 0;
	int j = 0;

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
	//printf("i -> %d\n", *i);
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
				size->map[i][j] = '1';
			}
			j++;
		}
		i++;
	}
}

void	continue_deep(t_size *size, t_cube *cube, t_coordinate *coordinate)
{
	int	i;
	int	j;
	int zero;

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
				break;
			}
			j++;
		}
		i++;
	}
	if (zero == 1)
		deep_algo(cube, size, coordinate, 1);

	else 
	{
		if (search_g(size->map) == -1)
			printf("ERROR -> MAP OUVERTE\n");
	}
	jsp(size->map);
	printf("\n");
		

	
}

