#include "../Cub3D.h"

void vrf_map2(int *j, int *k, int *i, t_size *size)
{
	if (size->map[*i][*j] == 'x' && (size->map[*i][*j + 1] == '#' || size->map[*i][*j - 1] == '#' 
		|| size->map[*i - 1][*j] == '#' || size->map[*i + 1][*j] == '#'))
				size->map[*i][*j] = 'G';
			--*k;
	if (*k > 0)
	{
		*i = size->tab_x[*k];
		*j = size->tab_y[*k];
	}
		
}

void	vrf_map(int *j, int *k, int *i,t_size *size, int nb)
{
	if (nb == 1)	
	{
		if (size->map[*i][*j + 1] == '0' )
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


char	**init_deep_algo(t_size *size, t_cube *cube, t_coordinate *coordinate)
{
	char **mapp;

	
	
	mapp = ft_strrdup(cube->true_map);
	search_begin(mapp, coordinate);
	size->tab_x = malloc(sizeof(int) * 10000);
	size->tab_y = malloc(sizeof(int) * 10000);
	find_map_dimensions(mapp, size);
	printf("%d\n", size->height);
	printf("%d\n", size->width);
	replace(mapp, size);
	size->map = ft_strrdup(contour(mapp, size));
	return (mapp);
}

void	init_deep_algo2(t_coordinate *coordinate, int *i, int *j, t_size *size)
{
	search_begin(size->map, coordinate); 
	*i = coordinate->x;
    *j = coordinate->y;
	size->tab_x[0] = *i;
	size->tab_y[0] = *j;
	
}

void	contour2(int i, int j, char ***new_map, t_size *size)
{
	char symbole;

	symbole = '#';

	if (i == 0 )
		(*new_map)[i][j] = symbole;
	else if (i == size->height - 1 )
		(*new_map)[i][j] = symbole;
	else if ( j == 0 || j == size->width - 1)
		(*new_map)[i][j] = symbole;	
	
}

void	contour3(int i, int j, char ***new_map, t_size *size)
{
	;
}