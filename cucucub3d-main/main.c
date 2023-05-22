/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:30:39 by mbouaza           #+#    #+#             */
/*   Updated: 2023/05/18 02:28:16 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

// key //

// to use the keypad for make many actions //

void	key(mlx_key_data_t	keydata, void *param)
{
	t_cube	*cube = param;

	if (mlx_is_key_down(cube->mlx, MLX_KEY_ESCAPE))
		quit_game(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_W) && possible_up(cube, cube->pov->instances[0].y, cube->pov->instances[0].x) != -1)
		move_up(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_S) && possible_down(cube, cube->pov->instances[0].y, cube->pov->instances[0].x))
		move_down(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_RIGHT))
		turn_right(cube);
	if (mlx_is_key_down(cube->mlx, MLX_KEY_LEFT))
		turn_left(cube);
	mlx_delete_image(cube->mlx, cube->angle);
	cube->angle = mlx_new_image(cube->mlx, windowWidth, windowHeight);
	load_map(cube);
	fox(cube, 0);
	mlx_image_to_window(cube->mlx, cube->angle, cube->px, cube->py);
}

// main //

int32_t main(int argc, char **argv)
{
	t_cube *cube;

	cube = malloc(sizeof(t_cube));
	if (argc != 2 || check_is_cub(argv[1]) == -1 || check_file(argv[1]) == -1)
		return (error_msg(0), free(cube), 1);
	if (init_struct(cube, argv) == -1)
		return (free_all_true(cube), -1);


	t_coordinate *coordinate; // rajout
	t_size *size; // rajout
	coordinate = malloc(sizeof(t_coordinate)); // rajout
	size = malloc(sizeof(t_size)); // rajout
	if (deep_algo(cube, size, coordinate)) //rajout
	{
		cube->mlx = mlx_init(windowWidth, windowHeight, "Cub3D", true);
		init_character(cube);
		fox(cube, 0);
		creat_map(cube);
		load_character(cube);
		mlx_key_hook(cube->mlx, &key, cube);
		mlx_loop(cube->mlx);
		free_all_true(cube);
		mlx_terminate(cube->mlx);
		exit(EXIT_SUCCESS);
	}
	
}