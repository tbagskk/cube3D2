/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:48:28 by mbouaza           #+#    #+#             */
/*   Updated: 2023/05/17 17:20:34 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

// ft_abs //

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

// draw_line //

void    draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color)
{
    int dx;
    int dy;
    int err;
    int e2;
    int    sx;
    int    sy;

    dx = ft_abs(x1 - x0);
    sx = x0 < x1 ? 1 : -1;
    dy = ft_abs(y1 - y0);
    sy = y0 < y1 ? 1 : -1;
    err = (dx > dy ? dx : -dy) / 2;
    while (1)
    {
        if (x0 >= 0 && x0 <= windowWidth && y0 >= 0 && y0 <= windowHeight)
            mlx_put_pixel(img, x0, y0, color);
        else
            return ;
        if (x0 == x1 && y0 == y1)
            break;
        e2 = err;
        if (e2 >-dx) 
        { 
            err -= dy; 
            x0 += sx; 
        }
        if (e2 < dy) 
        { 
            err += dx; 
            y0 += sy; 
        }
    }
}

// possible_up //

// if my ray of 10 touch the wall, i can't moving forward //

int possible_up(t_cube *cube, int y, int x)
{
    int height;
    
	x = sinf(cube->degre * DEG2PI) * 10 + x + 27;
	y = cosf(cube->degre * DEG2PI) * 10 + y + 30;
    printf("%d, %d\n", y / 64, x / 64);
    if (cube->true_map[y / 64][x / 64] == '1')
        return (-1);
    return (0);
}

int possible_down(t_cube *cube, int y, int x)
{
    int height;
	float angle;

	angle = cube->degre;
	x = sinf((angle + 180) * DEG2PI) * 5 + x + 27;
	y = cosf((angle + 180) * DEG2PI) * 5 + y + 30;
    printf("%d, %d\n", y / 64, x / 64);
    if (cube->true_map[y / 64][x / 64] == '1')
        return (0);
    return (-1);
}