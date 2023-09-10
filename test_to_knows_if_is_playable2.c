/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to_knows_if_is_playable2.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:47:47 by emedina-          #+#    #+#             */
/*   Updated: 2023/09/11 01:01:23 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lib1	*test_to_knows_if_is_playable2(t_lib1 *map_data)
{
	so_many_p_e_c_has(map_data, map_data->map_array);
	if (!isnt_borded_of_walls(map_data->map_array, map_data->how_many_lines,
			map_data->how_many_colums))
		exit(EXIT_FAILURE);
	ft_printf("\nMAP_ARRAY\n%s\n", map_data->cpy_of_map_array[0]);
	ft_printf("%s\n", map_data->cpy_of_map_array[1]);
	ft_printf("%s\n", map_data->cpy_of_map_array[2]);
	flood_fill(map_data, map_data->player_coor_x,
			map_data->player_coor_y);
	ft_printf("COPY_MAP_ARRAY\n%s\n", map_data->cpy_of_map_array[0]);
	ft_printf("%s\n", map_data->cpy_of_map_array[1]);
	ft_printf("%s\n", map_data->cpy_of_map_array[2]);
	find_out_if_is_playable(map_data);
	exit(EXIT_SUCCESS);
}

int	so_many_p_e_c_has(t_lib1 *map_data, char **map)
{
	int	p;
	int	e;
	int	c;

	c = count_p_e_c(map, map_data, 'C');
	p = count_p_e_c(map, map_data, 'P');
	e = count_p_e_c(map, map_data, 'E');
	if (c == 0 || p == 0 || e == 0 || p > 1 || e > 1)
	{
		perror("error\nnumero de monedas, salidas o jugadores incorrecto");
		return (1);
	}
	else
	{
		ft_printf("Numero de monedas, salidas y jugadores correcto");
		return (0);
	}
}

void	flood_fill(t_lib1 *map_data, int x, int y)
{
	if (map_data->cpy_of_map_array[x][y] != '1')
	{
		map_data->cpy_of_map_array[x][y] = '1';
		flood_fill(map_data, x + 1, y);
		flood_fill(map_data, x - 1, y);
		flood_fill(map_data, x, y + 1);
		flood_fill(map_data, x, y - 1);
	}
}

void find_out_if_is_playable(t_lib1 *map_data)
{
	int playable;
	playable = 1;
	while(map_data->x < map_data->how_many_lines && playable)
	{
		while(map_data->y < map_data->how_many_colums && playable)
		{
			if(map_data->cpy_of_map_array[map_data->x][map_data->y] != '1' && map_data->cpy_of_map_array[map_data->x][map_data->y] != '0')
			{
				playable = 0;
			}
			map_data->y++;
		}
		map_data->y = 0;
		map_data->x++;
	}
	if(playable)
		ft_printf("es jugable");
	else
		perror("error\nno es jugable");
}

/* 
		1 1 1 1 1
		1 0 1 0 1
		1 1 1 0 1
		1 0 0 0 1
		1 0 P 0 1
		1 0 0 0 1				P = 4(y/altura), 2(x/recorrido) -->
		1 1 1 1 1						
										
										1. vuleta he comprobado(sumer y restar 1) a las coordenadas de alrededor de P
											1.1 En caso de que sea un 1 no hacer nada else != 1
												-> F
										2. vuelta he comprobado(sumer y restar 2) a las coordenadas de alrededor de P
											2.1 En caso de que sea un 1 no hacer nada else != 1
												-> F
										3.  vuelta he comprobado(sumer y restar 3) a las coordenadas de alrededor de 
											3.1 En caso de que sea un 1 no hacer nada else != 1
												-> F
		
	//
*/