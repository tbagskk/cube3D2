/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:19:36 by mbouaza           #+#    #+#             */
/*   Updated: 2023/05/12 22:52:09 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

// check_is_cub //

// check if my map file is a .cub //

int check_is_cub(char *f)
{
	int i;

	i = ft_strlen(f) - 1;
	if (f[i - 3] == '.' && f[i - 2] == 'c' && f[i - 1] == 'u' && f[i] == 'b')
		return (1);
	error_msg(1);
	return (-1);
}

// check_file //

// check if my file is safe and readable //

int check_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		close(fd);
		error_msg(2);
		return (-1);
	}
	close(fd);
	return (1);
}

// check_map //

// check if my map has only 6 Character ( total ) but one of this character 'N', 'S', 'W', 'E' //

int check_map(char **map)
{
	int stat;
	int y;
	int x;

	y = -1;
	x = 0;
	stat = 0;
	replace2(map);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '0' || map[y][x] == '1' || map[y][x] == ' ' || map[y][x] == '\n' )
				;
			else if ((map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W'
				|| map[y][x] == 'E') && stat != 1)
				stat = 1;
			else
				return (error_msg(3), -1);
		}
	}
	if (stat == 1)
		return (1);
	return (error_msg(3), -1);
}

// check_args //

// check if my .cub has 6 parameters like ceiling color or texture for an specific direction //

int check_args(char **map)
{
	int y;
	int i;
	char **line;

	y = 0;
	i = 0;
	line = NULL;
	while (y < begining_map(map))
	{
		line = ft_split(map[y], ' ');
		if (size_of_tab(line) != 2 && size_of_tab(line) != 1)
			return (free_tab(line), -1);
		if (size_of_tab(line) == 2)
			i++;
		free_tab(line);
		y++;
	}
	if (i == 6)
		return (1);
	return (-1);
}

// begining_map //

// find the line where my map is write //

int begining_map(char **map)
{
	int y;
	int x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == ' ' || map[y][x] == '\t')
				x++;
			else if (map[y][x] != '1')
				y++;
			else
				return (y);
		}
	}
	return (y);
}