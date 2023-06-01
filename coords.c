/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:55:46 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/02/23 17:13:47 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	getcoords(t_coords *coords, t_map map)
{
	coords->startx = coords->endx;
	coords->starty = coords->endy;
	coords->endx = coords->startx + coords->linelen;
	coords->endy = coords->starty + coords->linelen / 2;
	shiftplane(coords, map);
	if (map.map[map.y][map.x] < 3)
		coords->color = 0x00008B;
	else if (map.map[map.y][map.x] > 3 && map.map[map.y][map.x] <= 9)
		coords->color = 0xADD8E6;
	else if (map.map[map.y][map.x] > 9 && map.map[map.y][map.x] <= 20)
		coords->color = 0x097969;
	else if (map.map[map.y][map.x] > 20 && map.map[map.y][map.x] <= 40)
		coords->color = 0xFFC300;
	else if (map.map[map.y][map.x] > 40 && map.map[map.y][map.x] <= 60)
		coords->color = 0xC70039;
	else if (map.map[map.y][map.x] > 60)
		coords->color = 0x900C3F;
}

void	getcoordsdown(t_coords *coords, t_map map)
{
	coords->startx = coords->endx;
	coords->starty = coords->endy;
	coords->endx = coords->startx - coords->linelen;
	coords->endy = coords->starty + coords->linelen / 2;
	shiftplanedown(coords, map);
	if (map.map[map.y][map.x] < 3)
		coords->color = 0x00008B;
	else if (map.map[map.y][map.x] > 3 && map.map[map.y][map.x] <= 9)
		coords->color = 0xADD8E6;
	else if (map.map[map.y][map.x] > 9 && map.map[map.y][map.x] <= 20)
		coords->color = 0x097969;
	else if (map.map[map.y][map.x] > 20 && map.map[map.y][map.x] <= 40)
		coords->color = 0xFFC300;
	else if (map.map[map.y][map.x] > 40 && map.map[map.y][map.x] <= 60)
		coords->color = 0xC70039;
	else if (map.map[map.y][map.x] > 60)
		coords->color = 0x900C3F;
}

void	getcoordsrow(t_coords *coords, t_map map, int i)
{
	static int	sx;
	static int	sy;
	static int	ex;
	static int	ey;

	if (i == 0)
	{
		sx = coords->startx;
		sy = coords->starty;
		ex = coords->endx;
		ey = coords->endy;
	}
	else
	{
		if (map.y > 0)
			map.diff = map.map[map.y][map.x] - map.map[map.y - 1][map.x];
		sx = sx - coords->linelen;
		sy = sy + coords->linelen / 2 - (3 * map.diff);
		ex = sx + coords->linelen;
		ey = sy + coords->linelen / 2;
	}
	coords->startx = sx;
	coords->starty = sy;
	coords->endx = ex;
	coords->endy = ey;
}

void	getcoordscol(t_coords *coords, t_map map, int i)
{
	static int	sx;
	static int	sy;
	static int	ex;
	static int	ey;

	if (i == 0)
	{
		sx = coords->startx;
		sy = coords->starty;
		ex = coords->endx;
		ey = coords->endy;
	}
	else
	{
		if (map.x > 0)
			map.diff = map.map[map.y][map.x] - map.map[map.y][map.x - 1];
		sx = sx + coords->linelen;
		sy = sy + coords->linelen / 2 - (3 * map.diff);
		ex = sx - coords->linelen;
		ey = sy + coords->linelen / 2;
	}
	coords->startx = sx;
	coords->starty = sy;
	coords->endx = ex;
	coords->endy = ey;
}
