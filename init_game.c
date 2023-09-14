/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:20:40 by emedina-          #+#    #+#             */
/*   Updated: 2023/09/15 01:15:52 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lib1	*init_game(t_lib1 *map_data)
{
	open_window(map_data);
	return (map_data);
}

void	open_window(t_lib1 *map_data)
{
	int x;
	int y;
	
	y = 0;
	x = 0;
	
	map_data->mlx = mlx_init();
	map_data->win = mlx_new_window(map_data->mlx, 1920, 1080, "Hello world");
	map_data->img = mlx_new_image(map_data->mlx, x * 64, y * 64);
	print_img(map_data);
	mlx_put_image_to_window(map_data->mlx, map_data->win, map_data->img, 0, 0);
	//mlx_loop_hook(map_data->mlx, );
	mlx_loop(map_data->mlx);
	mlx_destroy_window(map_data->mlx, map_data->win);
	free(map_data->mlx);
}
//poner la ruta de tus imagenes y seguir con el so_long de goiko de ejemplo.
void	print_img(t_lib1 *map_data)
{
	map_data->player = mlx_xpm_file_to_image(map_data->mlx, "i/risitas.xpm", \
		&map_data->width, &map_data->heigth);
	map_data->wall = mlx_xpm_file_to_image(map_data->mlx, "i/pared.xpm", &map_data->width, &map_data->heigth);
	map_data->ground = mlx_xpm_file_to_image(map_data->mlx, "i/hierba2.xpm", &map_data->width, &map_data->heigth);
	map_data->coin = mlx_xpm_file_to_image(map_data->mlx, "i/birra.xpm", &map_data->width, &map_data->heigth);
	map_data->exit = mlx_xpm_file_to_image(map_data->mlx, "i/cobete_off.xpm", &map_data->width, &map_data->heigth);
}