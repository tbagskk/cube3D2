/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:13:33 by mbouaza           #+#    #+#             */
/*   Updated: 2023/05/18 02:38:24 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static int ray_limite(int y, int x, float angle, t_cube *c, int *color)
{
	float height;
	float fx;
	float fy;
	float	ox, oy;

	height = 0;
	ox = 0;
	oy = 0;
	fx = 0;
	fy = 0;
	while (1)
	{
		fx = (sinf(angle * DEG2PI) * height + x) / 64;
		fy = (cosf(angle * DEG2PI) * height + y) / 64;
		if ((int)fx != (int)ox && (int)fy != (int)oy)
		{
			fx = (sinf((angle + 1) * DEG2PI) * height + x) / 64;
			fy = (cosf((angle + 1) * DEG2PI) * height + y) / 64;
			if ((int)fx != (int)ox)
				*color = LESS_RED;
			else
				*color = RED;
		}
		else if ((int)fx != (int)ox)
			*color = LESS_RED;
		else if ((int)fy != (int)oy)
			*color = RED;
		if (c->true_map[(int)fy][(int)fx] == '1')
			break;
		height += 1;
		ox = fx;
		oy = fy;
	}
	return (height);
}

void fox(t_cube *c, int i)
{
	float angle;
	int x;
	int y;
	int height;
	int	color;
	int ray_nb;

	angle = c->degre - 30;
	x = c->pov->instances[0].x + 27;
	y = c->pov->instances[0].y + 30;
	height = 0;
	mlx_delete_image(c->mlx, c->trois_des);
	c->trois_des = mlx_new_image(c->mlx, windowWidth, windowHeight);
	ray_nb = 480;
	i = ray_nb;
	while (--i >= 0)
	{
		height = ray_limite(y, x, angle, c, &color);
		angle += (float)60 / (float)ray_nb;
		// 3D //
		float  ca=(c->degre * DEG2PI)-(angle * DEG2PI); if (ca < 0){ca += 2 * PI;} if(ca > 2 * PI)  {ca -= 2 * PI;} height = height * cosf(ca);
		float lineH = (S * CUB_H) / height; if (lineH > CUB_H) {lineH = CUB_H;}
		float lineO = CUB_H / 2 - lineH / 2;
		for (int z = 0; z < (8 * CUB_W / ray_nb); z++)
		{
			draw_line(c->trois_des, (8 * CUB_W / ray_nb) * i + z, 0, (8 * CUB_W / ray_nb)* i + z, lineO, c->c_color);
			draw_line(c->trois_des, (8 * CUB_W / ray_nb) * i + z, lineO, (8 * CUB_W / ray_nb) * i + z, lineH +  lineO, color);
			draw_line(c->trois_des, (8 * CUB_W / ray_nb) * i + z, lineO+lineH, (8 * CUB_W / ray_nb) * i + z, CUB_H, c->f_color);
		}
	}
	mlx_image_to_window(c->mlx, c->trois_des, 0, 0);
	load_map(c);
}

void load_map(t_cube *c)
{
	int i;

	i = 0;
	while (i < c->map_count)
		mlx_delete_image(c->mlx, c->map_case[i++]);
	free(c->map_case);
	c->map_count = 0;
	c->map_case = malloc(sizeof(mlx_image_t) * (count_map(c->true_map) + 1));
	creat_map(c);
	mlx_delete_image(c->mlx, c->mini);
	load_character(c);
}

void load_character(t_cube *cube)
{
	int y;
	int x;
	int posx;
	int posy;
	
	y = 11;
	posy = (cube->pov->instances[0].y / 2);
	posx = (cube->pov->instances[0].x / 2);
	cube->mini = mlx_new_image(cube->mlx, 16 * 10, 16 * 10); // modife 
	while (y < 20)
	{
		x = 11;
		while (x < 20)
		{
			mlx_put_pixel(cube->mini, x, y, RED);
			x++;
		}
		y++;
	}
	mlx_image_to_window(cube->mlx, cube->mini , posx , posy);
}