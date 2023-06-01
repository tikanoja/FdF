/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:56:48 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/02/23 16:48:24 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	modhandler(int keycode, t_mlxinfo *mlx)
{
	if (keycode == 123)
		mlx->mod.x = mlx->mod.x - 20;
	else if (keycode == 124)
		mlx->mod.x = mlx->mod.x + 20;
	else if (keycode == 125)
		mlx->mod.y = mlx->mod.y + 20;
	else if (keycode == 126)
		mlx->mod.y = mlx->mod.y - 20;
	else if (keycode == 69)
		mlx->mod.zoom = mlx->mod.zoom + 2;
	else if (keycode == 78)
		mlx->mod.zoom = mlx->mod.zoom - 2;
}

int	key_hook(int keycode, t_mlxinfo *mlx)
{
	t_img	img;

	if (keycode == 53 || keycode == 6)
	{
		freeandexit(mlx);
	}
	if ((keycode >= 123 && keycode <= 126) || keycode == 69 || keycode == 78)
	{
		img.img = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
		img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.llen, &img.en);
		modhandler(keycode, mlx);
		drawgrid(*mlx->map, &img, mlx->coords, mlx);
		mlx_destroy_image(mlx->mlx_ptr, mlx->currentimg);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, img.img, 0, 0);
		mlx->currentimg = img.img;
	}
	return (0);
}

int	dimensioninit(t_map *map, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY, 0666);
	if (fd == -1)
		return (1);
	map->width = getwidth(av);
	map->height = getheight(av);
	return (0);
}

int	freeandexit(t_mlxinfo *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	free(mlx->mlx_ptr);
	freemap(*mlx->map);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlxinfo	mlx;
	t_img		img;
	t_map		map;
	t_coords	coords;
	int			y;

	y = 0;
	if (ac != 2)
		return (1);
	if (dimensioninit(&map, av) == 1)
		return (1);
	if (createmap(&map, av, y) == 1)
		return (1);
	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, WIN_W, WIN_H, "fdf");
	img.img = mlx_new_image(mlx.mlx_ptr, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.llen, &img.en);
	modinit(&mlx);
	drawgrid(map, &img, &coords, &mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, img.img, 0, 0);
	hookinit(&mlx, &coords, &map, &img);
	mlx_key_hook(mlx.mlx_win, key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, freeandexit, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
