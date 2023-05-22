#include "../Cub3D.h"

// ft_error //

// ft_putstr on stderror output //

static void ft_error(char *str)
{
	if (str)
		write(2, str, ft_strlen(str));
}

// error_msg //

// print a error message on the stderror output // 

void error_msg(int msg)
{	
	ft_error("Error\n");
	if (msg == 0)
		ft_error("Check your arguments ❌\n");
	else if (msg == 1)
		ft_error("file isn't a .cub ❌\n");
	else if (msg == 2)
		ft_error("the file isn't readable ❌\n");
	else if (msg == 3)
		ft_error("check your map ❌\n");
	else if (msg == 4)
		ft_error("check your <file.cub> ❌\n");
}

// free_all //

// free all char and struct or anithing //

void free_all_true(t_cube *cube)
{
	int i;

	i = 0;
	if (cube->map)
		free_tab(cube->map);
	if (cube->true_map)
		free_tab(cube->true_map);
	while (cube->map_case[i] && i < cube->map_count)
		mlx_delete_image(cube->mlx, cube->map_case[i++]);
	if (cube->map_case)
		free(cube->map_case);
	if (cube)
		free(cube);
}