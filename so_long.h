#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lib1
{
	size_t	len;
	size_t	heigth;
	char	**map;
	char	**cpy_of_map;
	int		player_coor_x;
	int		player_coor_y;
	int		how_many_lines;

}			t_lib1;

int			main(int argc, char **argv);
int			isnt_borded_of_walls(char **map_array, int rows_of_array,
				int cols_of_array);
int	hasnt_forbidden_char(char *map_content);
char	*check_name(char *map_name);
char	*check_extension(char *map_extension);
/* char		*ft_strjoin(char *s1, char *s2);
int			ft_printf(char const *str, ...);
char	*get_next_line(int fd); */

#endif