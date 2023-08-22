/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:47:02 by emedina-          #+#    #+#             */
/*   Updated: 2023/08/22 21:10:47 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

// ahora te toca hacer la una funcion que lea el archivo

/* void	read_map(int fd, char *map)
{
	char	*buff;
	int		leng;
	int		read_map;
	size_t	i;
	int		len;
	int		num_words;
	int		i;
	int		num_words;
	int		i;

	leng = ft_strlen(map);
	buff = malloc(leng * sizeof(char));
	if (!buff)
		return (NULL);
	read_map = 1;
	while (!ft_strchr(map, '\n') && read_map != 0)
	{
		read_map = read(fd, buff, 1);
		if (read_map == -1)
		{
			free(buff);
			free(map);
			return (NULL);
		}
		buff[read_map] = '\0';
		map = ft_strjoin(map, buff);
	}
	free(buff);
	return (map);
} */
/* size_t	ft_strlen(const char *s)
{
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
} */
/* bool have_4_walls ()
{
	
} */
static int	count_words(const char *str, char c)
{
	int num_words;
	int i;
	
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

/* bool is_playable(char **map)
{
	int	wall;
	int	player;
	int	coin;
	int	way;
	int	leng;
	int	i;

	wall = '1';
	player = 'P';
	coin = 'C';
	way = '0';
	
} */
/* void so_long() */

int	main(int argc, char **argv)
{
	char	*map_name_with_extension;
	char	*maps_directory;
	char	*full_path;
	char	*map_content;
	char	**map_array;
	int	map_length;
	int	rows_of_array;
	int	cols_of_array;
	if (argc == 2)
	{
		map_name_with_extension = check_extension(argv[1]);

		if (map_name_with_extension != NULL)
		{
			maps_directory = "maps/";
			full_path = (char *)ft_strjoin(maps_directory,
											map_name_with_extension);
			if (full_path == NULL)
			{
				perror("Error al asignar memoria\n");
				return (1);
			}
			else
			{
				map_length = how_length_is_the_map(full_path);
				if (map_length == 0)
				{
					free(full_path);
					return (-1);
				}
				map_content = read_map(full_path, map_length);
				if (!hasnt_forbidden_char(map_content))
				{
					free(full_path);
					free(map_content);
					return (-1);
				}
				map_array = ft_split(map_content, '\n');
				rows_of_array = count_words(map_content, '\n');
				cols_of_array = (map_length / rows_of_array) - 1;
				ft_printf("lineas del array: %d\n", rows_of_array);
				ft_printf("columnas del array: %d \n", cols_of_array);
				if (isnt_borded_of_walls(map_array, rows_of_array,
						cols_of_array))
				{
					free(full_path);
					free(map_content);
					return (-1);
				}
			}
			free(full_path);
			free(map_content);
		}
	}
	return (0);
}