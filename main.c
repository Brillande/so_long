/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:47:02 by emedina-          #+#    #+#             */
/*   Updated: 2023/08/30 15:33:33 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		wall;
	int		player;
	int		coin;
	int		way;
	int		leng;
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
/* bool is_playable(char **map)
{
	wall = '1';
	player = 'P';
	coin = 'C';
	way = '0';
	
} */
t_lib1	*so_long(t_lib1 *map_data, char *map)
{
	join_the_fullpath(map_data, map);
}

int	main(int argc, char **argv)
{
	t_lib1	*map_data;

	if (argc == 2)
	{
		ft_calloc(sizeof(*map_data), sizeof(*map_data));
		so_long(map_data, argv[1]);
	}
}
