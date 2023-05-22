#include "../Cub3D.h"



void jsp(char **map)
{
    
    int i = 0;
    int j = 0;
    while (map[i])
    {
        while (map[i][j])
        {
            printf("%c ",map[i][j]);
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


void print_tab(int *tab_x, int *tab_y)
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
	while(map[i])
	{
		j = 0;
		while(map[i][j])
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
				break;
			}
				
			j++;
		}
		i++;
	}
	
}

void find_map_dimensions(char **map, t_size *size)
{
    int i = 0;
    size->height = 0;
    size->width = 0;
	char **map_2;

    while (map[i] != NULL)
    {
        int row_length = ft_strlen(map[i]);
        if (row_length > size->width)
            size->width = row_length;
        i++;
    }
    size->height = i;
}

void	init_contour(char ***new_map, t_size *size)
{
	int	i;

	i = 0;
	*new_map = malloc(sizeof (char *) * (size->height + 1));
	while (i < size->height)
	{
		(*new_map)[i] = malloc(sizeof(char) * (size->width + 1));
		i++;
	}
}

char **contour(char **map, t_size *size)
{
	int	i;
	int	j;
	int l;
	int k;

	char **new_map;
	char symbole = '#';
	
	size->height+=2;
	size->width+=1;
	i = 0;
	l = 0;
	k = 0;
	

	init_contour(&new_map, size);
//	
	while (i < size->height)
	{
		j = 0;
		l = 0;
		while (j < size->width)
		{
			if (i == 0 || i == size->height - 1 || j == 0 || j == size->width - 1)
				contour2(i, j, &new_map, size);
			else
			{
				if (k < size->height - 2 && l < size->width - 1)
				{
					new_map[i][j] = map[k][l];
					l++;
				}
				else
					new_map[i][j] = ' ';
			}
			j++;
		}
		new_map[i][size->width] = '\0'; 
		if (i > 0)
		{
			k++;
			//size->k++;
		}
			//k++;
		i++;
	}
	new_map[size->height] = NULL;
	return (new_map);	
}

char **replace(char **map, t_size *size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size->height) // quand on met -1 ca segfault plus pour les grand tab
	{
		j = 0;
		while(j < size->width - 1)
		{
			if (!(map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'N'))
					map[i][j] = '#';
			
			j++;
		}
		i++;
	}
	return (map);
}

char **replace2(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        j = 0;
        while(map[i][j])
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
		while(map[i][j])
		{
			if (map[i][j] == 'G')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}



int deep_algo(t_cube *cube, t_size *size, t_coordinate *coordinate)
{
    int i;
    int j;
    int k;
	int dd;
	
	
    k = 1;
	i = 0;
	j = 0;
	dd = 0;
	init_deep_algo(size, cube, coordinate);
	init_deep_algo2(coordinate, &i, &j, size);
    while (dd < 20000)
    {
		if (size->map[i][j + 1] == '0' )
			vrf_map(&j, &k, &i, size, 1);
		else if (size->map[i][j - 1] == '0')
			vrf_map(&j, &k, &i,size, 1);
		else if ((i + 1 <=	size->height) && size->map[i + 1][j] == '0')
			vrf_map(&j, &k, &i,size, 1);
		else if ((i - 1 >= 0) && size->map[i - 1][j] == '0')
			vrf_map(&j, &k, &i,size, 1);
		else
			vrf_map(&j, &k, &i, size, 0);
		if (k < 0)	
			break;
		size->tab_x[k] = i;
		size->tab_y[k] = j;
		dd++;
    }
	
    jsp(size->map);
	printf("%d\n", dd);
	if (search_g(size->map) == -1)
		printf("la map n'est pas ferme\n");
	return (0);
}