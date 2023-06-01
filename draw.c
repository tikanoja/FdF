/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:57:11 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/02/23 17:25:28 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->llen + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	drawinit(t_bres *bres, t_coords *coords)
{
	bres->x = coords->startx;
	bres->y = coords->starty;
	bres->dx = abs(coords->endx - coords->startx);
	bres->dy = -abs(coords->endy - coords->starty);
	if (bres->x < coords->endx)
		bres->stepx = 1;
	else
		bres->stepx = -1;
	if (bres->y < coords->endy)
		bres->stepy = 1;
	else
		bres->stepy = -1;
	bres->error = bres->dx + bres->dy;
}

void	drawl(t_img *img, t_coords *coords, int color)
{
	t_bres	bre;

	drawinit(&bre, coords);
	while (1)
	{
		if (bre.x > 0 && bre.x < WIN_W && bre.y > 0 && bre.y < WIN_H)
			my_mlx_pixel_put(img, bre.x, bre.y, color);
		if (bre.x == coords->endx && bre.y == coords->endy)
			break ;
		bre.e2 = 2 * bre.error;
		if (bre.e2 >= bre.dy)
		{
			if (bre.x == coords->endx)
				break ;
			bre.error = bre.error + bre.dy;
			bre.x = bre.x + bre.stepx;
		}
		if (bre.e2 <= bre.dx)
		{
			if (bre.y == coords->endy)
				break ;
			bre.error = bre.error + bre.dx;
			bre.y = bre.y + bre.stepy;
		}
	}
}

void	advancehelper(t_map *map, int i)
{
	if (i == 1)
	{
		map->x = 0;
		map->y++;
	}
	else
	{
		map->y = 0;
		map->x++;
	}
}

void	drawgrid(t_map map, t_img *img, t_coords *coords, t_mlxinfo *mlx)
{
	scaler(&map, coords, 0, mlx);
	while (map.y < map.height)
	{
		getcoordsrow(coords, map, 1);
		while (map.x < map.width - 1)
		{
			getcoords(coords, map);
			drawl(img, coords, coords->color);
			map.x++;
		}
		advancehelper(&map, 1);
	}
	scaler(&map, coords, 1, mlx);
	while (map.x < map.width)
	{
		getcoordscol(coords, map, 1);
		while (map.y < map.height - 1)
		{
			getcoordsdown(coords, map);
			drawl(img, coords, coords->color);
			map.y++;
		}
		advancehelper(&map, 2);
	}
	justadot(img, map);
}
