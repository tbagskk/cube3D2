/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:54:19 by mbouaza           #+#    #+#             */
/*   Updated: 2023/05/18 02:07:21 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

// init map //

// copy the .cub //

char **init_map(char **argv)
{
	int fd;
	int size;
	char *line;
	char **map;

	size = map_size(argv);
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	map = malloc(sizeof(char *) * (size + 1));
	size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map[size] = ft_strdup(line);
		free(line);
		size++;
	}
	map[size] = NULL;
	close(fd);
	return (map);
}

void init_character(t_cube *cube)
{
	int y;
	int x;
	
	y = 27;
	cube->pov = mlx_new_image(cube->mlx, 25 * 180, 25 * 180); // modife 
	while (y < 37)
	{
		x = 27;
		while (x < 37)
		{
			mlx_put_pixel(cube->pov, x, y, 0xFFFFF);
			x++;
		}
		y++;
	}
	mlx_image_to_window(cube->mlx, cube->pov , cube->px * 64, cube->py * 64);
	cube->angle = mlx_new_image(cube->mlx, windowWidth, windowHeight);
	cube->trois_des = mlx_new_image(cube->mlx, 8 * 64, 8 * 64); // modife
}

// init strcut //

// init all variable of my struct and other //

int init_struct(t_cube *cube, char **argv)
{
	cube->map = init_map(argv);
	cube->true_map = copy_true_map(cube->map);
	if (check_all(cube) == -1)
		return (-1);
	cube->first_map = 0;
	cube->px = (float)find_px(cube->true_map, cube->character_letter);
	cube->py = (float)find_py(cube->true_map, cube->character_letter);
	find_color(cube, -1, 0, 0);
	init_texture(cube, 0);
	cube->map_count = 0;
	cube->map_case = malloc(sizeof(mlx_image_t) * (count_map(cube->true_map) + 1));
	orientation(cube);
	return (1);
}

// init_texture //

// find all path for texture for the orientation //

void init_texture(t_cube *c, int n)
{
	int j;
	char **texture;
	
	j = 0;
	while (c->map[j])
	{
		texture = ft_split(c->map[j], ' ');
		if (texture[0][0] == 'N' && texture[0][1] == 'O' && n == 0)
			c->no = ft_strdup(texture[1]);
		if (texture[0][0] == 'S' && texture[0][1] == 'O' && n == 1)
			c->so = ft_strdup(texture[1]);
		if (texture[0][0] == 'W' && texture[0][1] == 'E' && n == 2)
			c->we = ft_strdup(texture[1]);
		if (texture[0][0] == 'E' && texture[0][1] == 'A' && n == 3)
			c->ea = ft_strdup(texture[1]);
		free_tab(texture);
		j++;
	}
	if (n != 3)
		init_texture(c, n + 1);
}