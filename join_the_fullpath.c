/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_the_fullpath.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:22:49 by emedina-          #+#    #+#             */
/*   Updated: 2023/09/07 21:22:46 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lib1	*join_the_fullpath(t_lib1 *map_data, char *map_name)
{
	char	*map_name_with_extension;
	char	*maps_directory;

	map_name_with_extension = check_extension(map_name);
	if (map_name_with_extension != NULL)
	{
		maps_directory = "maps/";
		map_data->fullpath = ft_strjoin(maps_directory,
				map_name_with_extension);
		if (map_data->fullpath == NULL)
		{
			perror("Error\n al asignar memoria\n");
			exit(EXIT_FAILURE);
		}
		read_the_map(map_data);
	}
}

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
