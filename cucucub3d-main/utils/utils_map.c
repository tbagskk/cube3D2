/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:01:06 by mbouaza           #+#    #+#             */
/*   Updated: 2023/05/18 02:33:12 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

// draw_black_edge //

// draw a black edge for 2D map //

static void draw_black_edge(int y, int x, t_cube *c)
{
	int i;
	int j;

	j = 0;
	c->map_case[c->map_count] = mlx_new_image(c->mlx, S, S);
	while (j < S)
	{
		i = 0;
		while (i < S)
		{
			if (i == 0 || i == S - 1 || j == 0 || j == S - 1)
				mlx_put_pixel(c->map_case[c->map_count], i, j, GREY);
			else
				mlx_put_pixel(c->map_case[c->map_count], i, j, BLACK);
			i++;
		}
		j++;
	}
	mlx_image_to_window(c->mlx, c->map_case[c->map_count], x * S, y * S);
	c->map_count++;
}

// draw_white_edge //

// draw all white edge for 2D map // 

static void draw_white_edge(int y, int x, t_cube *c)
{
	int i;
	int j;

	j = 0;
	c->map_case[c->map_count] = mlx_new_image(c->mlx, S, S);
	while (j < S)
	{
		i = 0;
		while (i < S)
		{
			if (i == 0 || i == S - 1 || j == 0 || j == S - 1)
				mlx_put_pixel(c->map_case[c->map_count], i, j, GREY);
			else
				mlx_put_pixel(c->map_case[c->map_count], i, j, WHITE);
			i++;
		}
		j++;
	}
	mlx_image_to_window(c->mlx, c->map_case[c->map_count], x * S, y * S);
	c->map_count++;
}

// create the map //

// draw the mini-map //

void creat_map(t_cube *cube)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (cube->true_map[y])
	{
		x = 0;
		while (cube->true_map[y][x])
		{
			if (cube->true_map[y][x] == '0'
				|| cube->true_map[y][x] == cube->character_letter)
				draw_black_edge(y, x, cube);
			else if (cube->true_map[y][x] == '1')
				draw_white_edge(y, x, cube);
			x++;
		}
		y++;
	}
	cube->map_case[cube->map_count] = NULL;
}

// ft_pixel //

// with RGBA, can choice an colors //

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

// find_color //

// find the color for C and F //

void find_color(t_cube *c, int j, int choice, int choice2)
{
	char **color;
	char **tc;
	
	while (c->map[++j] || (choice != 1 && choice2 != 1))
	{
		color = ft_split(c->map[j], ' ');
		if (color[0][0] == 'C' && choice == 0)
		{
			tc = ft_split(color[1], ',');
			c->c_color = ft_pixel(fat(tc[0]), fat(tc[1]), fat(tc[2]), 255);
			free_tab(tc);
			choice = 1;
			j = 0;
		}
		else if (color[0][0] == 'F' && choice2 == 0)
		{
			tc = ft_split(color[1], ',');
			c->f_color = ft_pixel(fat(tc[0]), fat(tc[1]), fat(tc[2]), 255);
			free_tab(tc);
			choice2 = 1;
			j = 0;
		}
		free_tab(color);
	}
}
