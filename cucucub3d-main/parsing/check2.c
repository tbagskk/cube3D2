/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:48:06 by mbouaza           #+#    #+#             */
/*   Updated: 2023/05/13 21:46:34 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

// check if the map is close by wall //

int check_wall(char **map)
{
	(void)map;
	return (1);
}

// check_all //

// make all basic check for cub3d map // 

int check_all(t_cube *cube)
{	
	if (check_map(cube->true_map) == -1)
		return (-1);
	else if (check_args(cube->map) == -1)
		return (error_msg(4), -1);
	cube->character_letter = find_player_letter(cube->true_map);
	return (1);
}

// find_player_letter //

// return the letter specific for player //

char find_player_letter(char **map)
{
	int y;
	int x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N')
				return ('N');
			else if (map[y][x] == 'S')
				return ('S');
			else if (map[y][x] == 'W')
				return ('W');
			else if (map[y][x] == 'E')
				return ('E');
			x++;
		}
		y++;
	}
	return (0);
}