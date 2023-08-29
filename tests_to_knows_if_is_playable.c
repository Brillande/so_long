#include "ft_printf/ft_printf.h"
#include "so_long.h"

t_lib1 *test_to_knows_if_is_playable(t_lib1 map_update1)
{
	t_lib1 map_update2;

	if (!hasnt_forbidden_char(map_update1.map_content))
	{
		/* free(map_update.fullpath); */
		/* free(map_update.map_content); */
		exit (EXIT_FAILURE);
	}
	map_update2.map_array = ft_split(map_update1.map_content, '\n');
	map_update2.how_many_lines = count_words(map_update1.map_content, '\n');
	map_update2.how_many_colums = (map_update1.map_length / map_update2.how_many_lines) - 1;
	ft_printf("\nlineas del array: %d\n", map_update2.how_many_lines);
	ft_printf("columnas del array: %d \n", map_update2.how_many_colums);
	so_many_P_E_C_has(map_update2.map_array, map_update2.how_many_lines,
	map_update2.how_many_colums);
	if (isnt_borded_of_walls(map_update2.map_array, map_update2.how_many_lines,
	map_update2.how_many_colums))
	{
		/* free(map_update.fullpath); */
		/* free(map_update.map_content); */
		exit (EXIT_FAILURE);
	}
	/* free(map_update.fullpath); */
	/* free(map_update.map_content); */
}
	
t_lib1	*isnt_borded_of_walls(char **map_array, int lines, int colms)
{
	int x;
	int y;
	x = 0;

	while (x < lines)
	{
		y = 0;
		while (y < colms)
		{
			if (map_array[0][y] != '1' || map_array[lines
				- 1][y] != '1')
			{
				perror("\nerror\n no esta rodeado de muros1");
				return (0);
			}
			if (map_array[x][0] != '1' || map_array[x][colms] != '1')
			{
				perror("\nerror\n no esta rodeado de muros2");
				return (0);
			}
			y++;
		}
		x++;
	}
	exit (EXIT_SUCCESS);
}

int	hasnt_forbidden_char(char *map_content)
{
	int	i;

	i = 0;
	if (map_content)
	{
		while (map_content[i] != '\0')
		{
			if (map_content[i] != '1' && map_content[i] != '0'
				&& map_content[i] != 'C' && map_content[i] != 'E'
				&& map_content[i] != 'P' && map_content[i] != '\n')
			{
				perror("\nerror\n hay algun caracter prohibido");
				return (0);
			}
			i++;
		}
		ft_printf("\nno hay ningun caracter prohibido");
		return (1);
	}
	return (0);
}

static int	count_words(const char *str, char c)
{
	int	num_words;
	int	i;

	num_words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			++num_words;
			while (str[i] != '\0' && str[i] != c)
				++i;
		}
		else
			++i;
	}
	return (num_words);
}

int so_many_P_E_C_has(char **map_array, int lines, int colums)
{
	int C;
	int P;
	int E;
	int x;
	int y;

	C = 0;
	P = 0;
	E = 0;
	x = 0;
	while (x < lines)
	{
		y = 0;
		while (y < colums)
		{
			if (map_array[x][y] == 'C')
				C++;		
			else if (map_array[x][y] == 'P')
				P++;
			else if (map_array[x][y] == 'E')
				E++;
			y++;	
		}
		y = 0;
		x++;
	}	
	if(C == 0 || P == 0 || E == 0 || P > 1 || E > 1)
	{
		perror("error\n numero de monedas, salidas o jugadores incorrecto");
		return(1);
	}
	else
	{
		ft_printf("Numero de monedas, salidas y jugadores correcto");
		return(0);
	}
}