/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:13:58 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/02/23 18:32:52 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scaler(t_map *map, t_coords *coords, int i, t_mlxinfo *mlx)
{
	int	ll;

	ll = 1;
	while (ll * map->width <= WIN_W / 2 && ll * map->height <= WIN_H / 2)
		ll++;
	map->x = 0;
	map->y = 0;
	coords->linelen = ll + mlx->mod.zoom;
	coords->startx = WIN_W / 2 - 0.1 * (map->width * coords->linelen) \
		+ mlx->mod.x;
	coords->starty = WIN_H / 10 + mlx->mod.y;
	coords->endx = coords->startx + coords->linelen;
	coords->endy = coords->starty + coords->linelen / 2;
	coords->color = 0xFFFFFF;
	if (i == 0)
		getcoordsrow(coords, *map, 0);
	else
		getcoordscol(coords, *map, 0);
	map->diff = 0;
}

void	shiftplane(t_coords *coords, t_map map)
{
	int	diff;

	diff = map.map[map.y][map.x + 1] - map.map[map.y][map.x];
	if (map.map[map.y][map.x] != map.map[map.y][map.x + 1])
	{
		coords->endy = coords->endy - (3 * diff);
	}
}

void	shiftplanedown(t_coords *coords, t_map map)
{
	int	diff;

	diff = map.map[map.y + 1][map.x] - map.map[map.y][map.x];
	if (map.map[map.y][map.x] != map.map[map.y + 1][map.x])
	{
		coords->endy = coords->endy - (3 * diff);
	}
}
