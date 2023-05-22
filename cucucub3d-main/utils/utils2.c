/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:08:20 by mbouaza           #+#    #+#             */
/*   Updated: 2023/05/16 00:28:46 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

// size_of_tab //

// return the size of char ** //

int size_of_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

// cout_map //

// count all map block //

int count_map(char **map)
{
	int y;
	int x;
	int i;

	i = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == '1' || map[y][x] == 'N')
				i++;
			else if (map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

// find_px //

int find_px(char **map, char c)
{
	int y;
	int x;
	int i;

	i = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

// find_py //

int find_py(char **map, char c)
{
	int y;
	int x;
	int i;

	i = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

// marche pas trop //

void  orientation(t_cube *cube)
{
	char c;

	c = cube->character_letter;
	if (c == 'N')
		cube->degre = 180;
	if (c == 'W')
		cube->degre = 270;
	if (c == 'S')
		cube->degre = 0;
	if (c == 'E')
		cube->degre = 90;
}