/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirandsssg <mirandsssg@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:08:26 by mirandsssg        #+#    #+#             */
/*   Updated: 2025/05/23 21:05:03 by mirandsssg       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "includes/get_next_line/get_next_line.h"
# include "includes/libftprintf/ft_printf.h"
# include "includes/libft/libft.h"
# include "includes/minilibx-linux/mlx.h"
# include "includes/minilibx-linux/mlx_int.h"

# define ESC 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP_KEY 65362
# define DOWN_KEY 65364
# define RIGHT_KEY 65363
# define LEFT_KEY 65361

typedef struct s_data
{
	int		columns;
	int		rows;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	int		player_x;
	int		player_y;
	int		steps;
	int		collectible_count;
	char	next_pos;
	char	curr_pos;
}	t_data;

int		ft_exit(t_data *data);

// Initialize
void	print_map(char **map);
int		line_count(const char *filename);
int		initialize_vars(char *map, t_data *data);
int		read_map_into_data(char *map, t_data *data);

// Parsing
size_t	str_len_no_nl(const char *s);
int		ber_extension(const char *filename);
int		is_valid_char(char c);
int		validade_char(char **map);
int		is_rectangular(char **map, t_data data);
int		parse_map1(char **map, const char *filename, t_data data);
int		parse_map2(char **map, t_data data);
int		check_char(char **map);
int		top_or_bottom_row(char *row);
int		is_surrounded(char **map, t_data data);
void	count_map_elements(char **map, int *p, int *e, int *c);
int		ft_strcmp(const char *s1, const char *s2);
int		is_bigger_than_window(t_data data);

// Floodfill
void	floodfill(char **map, int x, int y);
char	**copy_map(char **map, int rows);
void	find_player(t_data *data, int *px, int *py);
int		is_reachable(char **map);
int		is_path_valid(t_data *data);

// MLX
int		initialize_mlx(t_data *data);
int		draw_map(t_data *data);
int		load_images(t_data *data);
int		key_handler(int key_pressed, t_data *data);
void	free_map(t_data *data);

// MOVE
void	move_up(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_down(t_data *data);
void	attempt_move(t_data *data, int new_x, int new_y);
void	move(t_data *data, int new_x, int new_y);

#endif
