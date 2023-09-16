/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:20:40 by emedina-          #+#    #+#             */
/*   Updated: 2023/09/16 17:47:57 by emedina-         ###   ########.fr       */
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
	int	x;
	int	y;

	y = 0;
	x = 0;
	map_data->end = 0;
	map_data->count = 0;
	map_data->mlx = mlx_init();
	map_data->win = mlx_new_window(map_data->mlx, 1000, 1000, "Hello world");
	map_data->img = mlx_new_image(map_data->mlx, x * 64, y * 64);
	select_img(map_data);
	mlx_loop_hook(map_data->mlx, print_img, map_data);
	mlx_key_hook(map_data->win, key_hook, map_data);
	mlx_hook(map_data->win, 17, 0, exit_game, map_data);
	mlx_loop(map_data->mlx);
}

void	select_img(t_lib1 *map_data)
{
	map_data->player = mlx_xpm_file_to_image(map_data->mlx, "img/player.xpm",
			&map_data->width, &map_data->heigth);
	map_data->wall = mlx_xpm_file_to_image(map_data->mlx, "img/wall.xpm",
			&map_data->width, &map_data->heigth);
	map_data->ground = mlx_xpm_file_to_image(map_data->mlx, "img/ground.xpm",
			&map_data->width, &map_data->heigth);
	map_data->coin = mlx_xpm_file_to_image(map_data->mlx, "img/coin.xpm",
			&map_data->width, &map_data->heigth);
	map_data->exit = mlx_xpm_file_to_image(map_data->mlx, "img/exit.xpm",
			&map_data->width, &map_data->heigth);
}

int	print_img(t_lib1 *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (map_data->map_array[i][j] == 'E')
		exit_game(map_data);
	print_img1(map_data);
	print_img2(map_data);
	print_img3(map_data);
	return (0);
}

void	print_img1(t_lib1 *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (map_data->map_array[i])
	{
		j = 0;
		while (map_data->map_array[i][j] != '\0')
		{
			if (map_data->map_array[i][j] != '1')
				mlx_put_image_to_window(map_data->mlx, map_data->win,
						map_data->ground, j * 65, i * 65);
			if (map_data->map_array[i][j] == '1')
				mlx_put_image_to_window(map_data->mlx, map_data->win,
						map_data->wall, j * 62, i * 62);
			j++;
		}
		i++;
	}
}

void	print_img2(t_lib1 *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (map_data->map_array[i])
	{
		j = 0;
		while (map_data->map_array[i][j] != '\0')
		{
			if (map_data->map_array[i][j] == 'C')
				mlx_put_image_to_window(map_data->mlx, map_data->win,
						map_data->coin, j * 80, i * 80);
			if (map_data->map_array[i][j] == 'E')
				mlx_put_image_to_window(map_data->mlx, map_data->win,
						map_data->exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	print_img3(t_lib1 *map_data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map_data->map_array[i][j] != 'P')
	{
		j++;
		if (map_data->map_array[i][j] == '\0')
		{
			j = 0;
			i++;
		}
	}
	mlx_put_image_to_window(map_data->mlx, map_data->win, map_data->player, j
			* 64, i * 55);
}

int	key_hook(int keycode, t_lib1 *map_data)
{
	int	y;
	int	x;

	x = map_data->player_coor_x;
	y = map_data->player_coor_y;
	if (keycode == 53)
		exit_game(map_data);
	else if (keycode == 13)
		move(map_data, x - 1, y);
	else if (keycode == 1)
		move(map_data, x + 1, y);
	else if (keycode == 0)
		move(map_data, x, y - 1);
	else if (keycode == 2)
		move(map_data, x, y + 1);
	return (0);
}

int	move(t_lib1 *map_data, int x, int y)
{
	if (x < 0 || x >= map_data->how_many_lines || y < 0
		|| y >= map_data->how_many_colums || map_data->map_array[x][y] == '1')
	{
		return (0);
	}
	if (map_data->map_array[x][y] == 'C')
	{
		map_data->coins_collected++;
		map_data->map_array[x][y] = '0';
	}
	if (map_data->map_array[x][y] == 'E'
		&& map_data->coins_collected == map_data->total_coins)
	{
		exit_game(map_data);
	}
	map_data->map_array[map_data->player_coor_x][map_data->player_coor_y] = '0';
	map_data->map_array[x][y] = 'P';
	map_data->player_coor_x = x;
	map_data->player_coor_y = y;
	map_data->count++;
	ft_printf("\nMovimientos: %i\n", map_data->count);
	return (0);
}

int	exit_game(t_lib1 *map_data)
{
	mlx_destroy_window(map_data->mlx, map_data->win);
	free(map_data->mlx);
	exit(EXIT_SUCCESS);
}
