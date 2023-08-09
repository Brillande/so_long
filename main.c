/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:47:02 by emedina-          #+#    #+#             */
/*   Updated: 2023/08/09 12:49:42 by emedina-         ###   ########.fr       */
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

int how_length_is_the_map(char *full_path)
{
	int file;
	char *buff[1];
	int i;
	
	i = 0;
	file = open(full_path, O_RDONLY);
	if (file == -1)
	{
		perror("ERROR en how_length_has_the_map \n No se pudo abrir el archivo\n");
		return (1);
	}
	else
	{
		ft_printf("%s\n", "se abrio el archivo en how_length_has_the_map");
		while(read(file, buff, 1))
			i++;
		close(file);
		ft_printf("longitud del fichero: %i\n",i);
			if(i < 1)
				return(close(file), perror("error, mapa vacio"),0);
			return (i);
	}
}

char  *read_map(char *full_path, int i)
{
	char *buff;
	int file;
	
	buff = malloc(sizeof(char *) * (i + 1));
	if(buff == NULL)
		return(NULL);
	file = open(full_path,O_RDONLY);
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
}

int has_forbidden_char(char *map_content)
{
	int i;

	i = 0;
	if(map_content)
	{
		while(map_content[i] != '\0')
		{
			if (map_content[i] != '1' && map_content[i] != '0' && map_content[i] != 'C' && map_content[i] != 'E' && map_content[i] != 'P' && map_content[i] != '\n')
			{
				perror("error, hay algun caracter prohibido");
				return(0);
			}
			i++;
		}
		ft_printf("%s\n","no hay ningun caracter prohibido");
		return(1);
	}
}


/* bool is_playable(char **map)
{
	int wall = '1';
	int player = 'P';
	int coin = 'C';
	int way = '0';
	
} */

char	*check_name(char *map_name)
{
	int	leng;
	int	i;

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

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *map_name_with_extension;
		char *maps_directory;
		char *full_path;
		char *map_content;
		char **map_array;
		int map_length;
		
		map_name_with_extension = check_extension(argv[1]);

		if (map_name_with_extension != NULL)
		{
			maps_directory = "maps/";
			full_path = (char *)ft_strjoin(maps_directory, map_name_with_extension);
			if (full_path == NULL)
			{
				perror("Error al asignar memoria\n");
				return (1);
			}
			else
			{
				map_length = how_length_is_the_map(full_path);
				if(map_length == 0)
				{
					free(full_path);
					return(-1);
				}
				map_content = read_map(full_path,map_length);
				if(!has_forbidden_char(map_content))
				{
					free(full_path);
					free(map_content);
					return(-1);
				}
				map_array = ft_split(map_content,'\n');
				
			} 
			free(full_path);
		}
	}
	return (0);
}