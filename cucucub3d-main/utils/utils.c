#include "../Cub3D.h"

// ft_strdup //

// strcpy but with malloc //

char	*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*dest;

	len = ft_strlen(s1);
	i = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// map_size //

// return the size y of the .cub //

int map_size(char **argv)
{
	int fd;
	int size;
	char *line;

	size = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		free(line);
		size++;
	}
	close(fd);
	return (size);
}

// free_tab //

// free for a char ** //

void free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

// quit_game //

// just for quit the game //

void quit_game(t_cube *cube)
{
	mlx_close_window(cube->mlx);
	free_all_true(cube);
	exit(EXIT_SUCCESS);
}

// copy_true_map //

// copy the .cub but only the map //

char **copy_true_map(char **map)
{
	char **true_map;
	int start;
	int y;

	start = begining_map(map);
	true_map = NULL;
	y = 0;
	while (map[start + y])
		y++;
	true_map = malloc(sizeof(char *) * (y + 1));
	y = 0;
	while (map[start + y])
	{
		true_map[y] = ft_strdup(map[start + y]);
		y++;
	}
	true_map[y] = NULL;
	return (true_map);
}