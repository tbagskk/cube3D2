#ifndef CUB3D_H
#define CUB3D_H

# define S 32
# define TURNSPEED 3
# define PI 3.1415926535
# define DEG2PI 0.0174533
# define SHEESH 3
# define CUB_H 320 * SHEESH
# define CUB_W 64 * SHEESH
# define windowWidth 8 * 64 * SHEESH
# define windowHeight (8 * 64 - 190) * SHEESH

// color //

# define BLACK    0x000000FF
# define WHITE    0xFFFFFFFF
# define GREY     0x808080FF
# define RED      0xFF0000FF
# define LESS_RED 0xCC0000FF
# define BLUE     0x0000FFFF

// include //

# include  <math.h>
# include  <stdio.h>
# include  <stdlib.h>
# include  <unistd.h>
# include  <fcntl.h>
# include  "MLX42/include/MLX42/MLX42.h"
# include  "get_next_line/get_next_line.h"

// struct //

typedef struct s_cube
{
	mlx_t 			*mlx;
	mlx_image_t 	*pov;
	mlx_image_t		*mini;
	mlx_image_t 	*angle;
	mlx_image_t		*trois_des;
	mlx_image_t		**map_case;
	mlx_image_t		*test;
	uint32_t		f_color;
	uint32_t		c_color;
	char 			*no;
	char 			*so;
	char 			*we;
	char 			*ea;
	char			character_letter;
	char			**map;
	char			**true_map;
	float			px;
	float			py;
	int 			map_count;
	int 			first_map;
	float			degre;
}				t_cube;

typedef struct	s_size  //rajout
{
	int	height;
	int	width;
	int	*tab_x;
	int	*tab_y;
	char **map;
	int	kk;
	int l;
}		t_size;

typedef struct	s_coordinate //rajout
{
	int	y;
	int	x;
}		t_coordinate;


// function //

// src/init.c //

char 	**init_map(char **argv);
void	init_character(t_cube *cube);
int		init_struct(t_cube *cube, char **argv);
void 	init_texture(t_cube *c, int n);

// src/fov.c //

void 	fox(t_cube *cube, int i);
void 	load_map(t_cube *c);
void 	load_character(t_cube *cube);

// src/key_action.c //

void 	move_up(t_cube *cube);
void 	move_down(t_cube *cube);
void 	turn_right(t_cube *cube);
void 	turn_left(t_cube *cube);

// parsing/check.c //

int 	check_is_cub(char *f);
int 	check_file(char *file);
int 	check_map(char **map);
int		begining_map(char **map);
int 	check_args(char **map);

// parsing/check2.c //

int 	check_wall(char **map);
int 	check_all(t_cube *cube);
char 	find_player_letter(char **map);

// utils/utils.c //

char	*ft_strdup(char *s1);
int 	map_size(char **argv);
void 	free_tab(char **tab);
void 	quit_game(t_cube *cube);
char 	**copy_true_map(char **map);

// utils/utils2.c //

int 	size_of_tab(char **tab);
int 	count_map(char **map);
int 	find_px(char **map, char c);
int 	find_py(char **map, char c);
void 	orientation(t_cube *cube);

// utils/utils_map.c //

void 	reload_map(t_cube *cube);
void 	creat_map(t_cube *cube);
void 	make_character(t_cube *cube);
void 	find_color(t_cube *c, int j, int choice, int choice2);

// utils/utils_error.c //

void 	error_msg(int msg);
void 	free_all_true(t_cube *cube);
int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

// utils/utils_move.c //

int 	return_py(t_cube *cube);
int 	return_px(t_cube *cube);
void    draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color);
int 	possible_up(t_cube *cube, int y, int x);
int 	possible_down(t_cube *cube, int y, int x);
int		ft_abs(int nb);

// utils/ft_split.c //

char	**ft_split(char const *s, char c);

// utils/ft_atoi.c //

int		fat(char *str);

// utils/utils_move.c //

// gabin function

void jsp(char **map);
int deep_algo(t_cube *cube, t_size *size, t_coordinate *coordinate);
char **replace2(char **map);
void	vrf_map(int *j, int *k, int *i, t_size *size, int nb);
char	**ft_strrdup(char **s1);
char	**init_deep_algo(t_size *size, t_cube *cube, t_coordinate *coordinate);
void	search_begin(char **map, t_coordinate *coordinate);
char **replace(char **map, t_size *size);
void find_map_dimensions(char **map, t_size *size);
char **contour(char **map, t_size *size);
void	init_deep_algo2(t_coordinate *coordinate, int *i, int *j, t_size *size);
int	ft_strrlen(char **str);
void	contour2(int i, int j, char ***new_map, t_size *size);



#endif