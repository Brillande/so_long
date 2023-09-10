/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_the_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:23:01 by emedina-          #+#    #+#             */
/*   Updated: 2023/09/11 01:01:41 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lib1	*read_the_map(t_lib1 *map_data)
{
	map_data->map_length = how_length_is_the_map(map_data->fullpath);
	if (map_data->map_length == 0)
	{
		exit(EXIT_FAILURE);
	}
	map_data->map_content = read_map(map_data->fullpath,
			map_data->map_length);
	return(map_data);
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
		perror("error\n en read_map: no se pudo abrir el archivo");
	else
	{
		ft_printf("%s\n", "Se abrio el archivo en read_map");
		read(file, buff, i);
		buff[i] = '\0';
		close(file);
		ft_printf("el mapa que has leido tiene la siguiente forma: \n%s", buff);
		return (buff);
	}
	return (NULL);
}

int	how_length_is_the_map(char *full_path)
{
	int		file;
	char	*buff[1];
	int		i;

	/* ft_printf("%s\n hola", full_path); */
	i = 0;
	file = open(full_path, O_RDONLY);
	if (file == -1)
	{
		perror("ERROR\n en how_length_has_the_map \n \
		No se pudo abrir el archivo\n");
		return (1);
	}
	else
	{
		ft_printf("%s\n", "se abrio el archivo en how_length_has_the_map");
		while (read(file, buff, 1))
		{
			i++;
		}
		close(file);
		ft_printf("longitud del fichero: %i\n", i);
		if (i < 1)
			return (close(file), perror("error,\n mapa vacio"), 0);
		return (i);
	}
}
