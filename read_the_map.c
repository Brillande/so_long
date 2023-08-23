#include "so_long.h"

int	how_length_is_the_map(char *full_path)
{
	int		file;
	char	*buff[1];
	int		i;

	i = 0;
	file = open(full_path, O_RDONLY);
	if (file == -1)
	{
		perror("ERROR en how_length_has_the_map \n \
		No se pudo abrir el archivo\n");
		return (1);
	}
	else
	{
		ft_printf("%s\n", "se abrio el archivo en how_length_has_the_map");
		while (read(file, buff, 1))
			i++;
		close(file);
		ft_printf("longitud del fichero: %i\n", i);
		if (i < 1)
			return (close(file), perror("error, mapa vacio"), 0);
		return (i);
	}
}

char	*read_map(char *full_path, int i)
{
	char	*buff;
	int		file;

	buff = malloc(sizeof(char *) * (i + 1));
	if (buff == NULL)
		return (NULL);
	file = open(full_path, O_RDONLY);
	if (file == -1)
		perror("error en read_map: no se pudo abrir el archivo");
	else
	{
		ft_printf("%s\n", "Se abrio el archivo en read_map");
		read(file, buff, i);
		buff[i] = '\0';
		close(file);
		printf("el mapa que has leido tiene la siguiente forma: \n%s", buff);
		return (buff);
	}
	return (NULL);
}

char *read_the_map(char *map)
{
	char	*map_content;
	int	map_length;

	map_length = how_length_is_the_map(map);
	if (map_length == 0)
		{
			free(map);
			exit(1);
		}
	map_content = read_map(map, map_length);
	return(map_content);
}