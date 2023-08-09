#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

typedef struct s_lib1
{
	size_t len;
	size_t heigth;
	char	**map;
	char	**cpy_of_map;
	int	player_coor_x;
	int player_coor_y;
	int how_many_lines;
	

}			t_lib1;

int			main(int argc, char **argv);
char	*get_next_line(int fd);
/* char		*ft_strjoin(char *s1, char *s2);
int			ft_printf(char const *str, ...);
char		*get_next_line(int fd); */

#endif