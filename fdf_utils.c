/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:25:58 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/02/23 17:27:37 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	modinit(t_mlxinfo *mlx)
{
	mlx->mod.x = 0;
	mlx->mod.y = 0;
	mlx->mod.zoom = 0;
}

void	hookinit(t_mlxinfo *mlx, t_coords *coords, t_map *map, t_img *img)
{
	mlx->coords = coords;
	mlx->map = map;
	mlx->currentimg = img->img;
}

void	freemap(t_map map)
{
	int	y;

	y = 0;
	while (y < map.height)
	{
		free(map.map[y]);
		y++;
	}
	if (map.map[y] != NULL)
		free(map.map);
}

void	justadot(t_img *img, t_map map)
{
	if (map.width == 1 && map.height == 1)
		my_mlx_pixel_put(img, WIN_W / 2, WIN_H / 2, 0xFFFFFF);
}
