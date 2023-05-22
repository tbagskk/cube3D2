/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:53:21 by mbouaza           #+#    #+#             */
/*   Updated: 2023/05/17 17:19:22 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

// move_up //

// move towards the line //

void move_up(t_cube *cube)
{
	int x;
	int y;

	x = sinf(cube->degre * DEG2PI) * 5;
	y = cosf(cube->degre * DEG2PI) * 5;
	cube->pov->instances[0].y += y;
	cube->pov->instances[0].x += x;
	//refresh_position(cube);
}

// move_down //

// advance in the opposite direction of the line //

void move_down(t_cube *cube)
{
	int x;
	int y;

	x = sinf(cube->degre * DEG2PI) * 5;
	y = cosf(cube->degre * DEG2PI) * 5;
	cube->pov->instances[0].y -= y;
	cube->pov->instances[0].x -= x;

}

// turn_right //

// turn the angle in degres //

void turn_right(t_cube *cube)
{
	if (cube->degre > 0)
		cube->degre -= 3;
	else
		cube->degre = 360;
}

// turn_left //

// turn the angle in degres //

void turn_left(t_cube *cube)
{
	if (cube->degre < 360)
		cube->degre += 3;
	else
		cube->degre = 0;
}