/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:20:40 by emedina-          #+#    #+#             */
/*   Updated: 2023/09/13 16:16:25 by emedina-         ###   ########.fr       */
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
	map_data->mlx = mlx_init();
	map_data->win = mlx_new_window(map_data->mlx, 1920, 1080, "Hello world");
	map_data->img = mlx_new_image(,map_data->mlx, x * 64, y * 64);
	choose_img(map_data);
	mlx_put_image_to_window(map_data->mlx, map_data->win, map_data->img, 0, 0);
	mlx_loop_hook(map_data->mlx, );
	mlx_loop(map_data->mlx);
	mlx_destroy_window(map_data->mlx, map_data->win);
	free(map_data->mlx);
}