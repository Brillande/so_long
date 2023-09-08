/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:23:09 by emedina-          #+#    #+#             */
/*   Updated: 2023/09/08 19:08:48 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* typedef struct s_point
{
	int		x;
	int		y;
}			t_point;
 */
typedef struct s_lib1
{
	char	**map_array;
	char	**cpy_of_map_array;
	int		player_coor_x;
	int		player_coor_y;
	int		how_many_lines;
	int		how_many_colums;
	int		map_length;
	int		x;
	int		y;
	int		count;
	char	*fullpath;
	char	*map_content;
}			t_lib1;

int			main(int argc, char **argv);
t_lib1		*so_long(t_lib1 *map_data, char *map);
t_lib1		*isnt_borded_of_walls(char **map_array, int lines, int colms);
int			hasnt_forbidden_char(char *map_content);
char		*check_name(char *map_name);
char		*check_extension(char *map_extension);
t_lib1		*join_the_fullpath(t_lib1 *map_data, char *map_name);
t_lib1		*read_the_map(t_lib1 *map_data);
char		*read_map(char *full_path, int i);
int			how_length_is_the_map(char *full_path);
t_lib1		*test_to_knows_if_is_playable(t_lib1 *map_data);
static int	count_words(const char *str, char c);
int			so_many_p_e_c_has(t_lib1 *map_data, char **map, int rows, int cols);
t_lib1		*test_to_knows_if_is_playable2(t_lib1 *map_data);
int			count_p_e_c(char **map, t_lib1 *map_data, char target);
int			flood_fill(t_lib1 *map_data, int x, int y);
#endif