/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:47:02 by emedina-          #+#    #+#             */
/*   Updated: 2023/08/23 15:24:59 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// haz una estructura que te hace falta para poder usar la funcion map_length en tu funsion so_long

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
int so_long(char *map)
{
	char	**map_array;
	int	rows_of_array;
	int	cols_of_array;
	if (map)
	{
		read_the_map(join_the_fullpath(map));
		if (!hasnt_forbidden_char(map))
		{
		/* free(full_path);
		free(map_content); */
		return (-1);
		}
		map_array = ft_split(map, '\n');
		rows_of_array = count_words(map, '\n');
		cols_of_array = (map_length / rows_of_array) - 1;
		ft_printf("lineas del array: %d\n", rows_of_array);
		ft_printf("columnas del array: %d \n", cols_of_array);
		if (isnt_borded_of_walls(map_array, rows_of_array,
		cols_of_array))
		{
			/* free(full_path);
			free(map_content); */
			return (-1);
		}
	}
	/* free(full_path);
	free(map_content); */
	return (0);
	}
	

	
int	main(int argc, char **argv)
{
	so_long(argv[1]);
}