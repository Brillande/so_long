#include "ft_printf/ft_printf.h"
#include "so_long.h"

int	isnt_borded_of_walls(char **map_array, int rows_of_array, int cols_of_array)
{
	int x;
	int y;
	x = 0;

	while (x < rows_of_array)
	{
		y = 0;
		while (y < cols_of_array)
		{
			if (map_array[0][y] != '1' || map_array[rows_of_array
				- 1][y] != '1')
			{
				perror("error no esta rodeado de muros1");
				return (0);
			}
			if (map_array[x][0] != '1' || map_array[x][cols_of_array] != '1')
			{
				perror("error no esta rodeado de muros2");
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
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
				perror("error, hay algun caracter prohibido");
				return (0);
			}
			i++;
		}
		ft_printf("%s\n", "no hay ningun caracter prohibido");
		return (1);
	}
	return (0);
}
char	*check_name(char *map_name)
{
	int leng;
	int i;
	
	leng = 0;
	i = 0;
	leng = ft_strlen(map_name);
	ft_printf("%s", "El nombre del archivo es: ");
	ft_printf("%s\n", &map_name[i]);
	return (map_name);
}
char	*check_extension(char *map_extension)
{
	int	leng;

	leng = 0;
	leng = ft_strlen(map_extension);
	if (map_extension[leng - 1] == 'r' && map_extension[leng - 2] == 'e'
		&& map_extension[leng - 3] == 'b' && map_extension[leng - 4] == '.')
	{
		write(1, "La extension es .ber\n", 21);
		check_name(map_extension);
		return (map_extension);
	}
	else
	{
		write(1, "Error\nLa extension no es .ber\n", 30);
		return (NULL);
	}
}