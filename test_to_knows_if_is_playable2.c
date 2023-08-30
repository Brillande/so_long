/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to_knows_if_is_playable2.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:47:47 by emedina-          #+#    #+#             */
/*   Updated: 2023/08/30 15:14:54 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lib1	*test_to_knows_if_is_playable2(t_lib1 map_update2)
{
	so_many_p_e_c_has(map_update2.map_array, map_update2.how_many_lines,
			map_update2.how_many_colums);
	if (isnt_borded_of_walls(map_update2.map_array, map_update2.how_many_lines,
			map_update2.how_many_colums))
		exit(EXIT_FAILURE);
}

int	so_many_p_e_c_has(char **map, int rows, int cols)
{
	int	c;
	int	p;
	int	e;

	c = count_p_e_c(map, rows, cols, 'C');
	p = count_p_e_c(map, rows, cols, 'P');
	e = count_p_e_c(map, rows, cols, 'E');
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

int	can_collect_all_coins_and_go_exit(char *cpy_of_map_array)
{
}