/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuukka <tuukka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:18:19 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/02/23 19:04:51 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "./libft/libft.h"
# define WIN_W 1920
# define WIN_H 1080

typedef struct s_mod
{
	int				x;
	int				y;
	int				zoom;
}				t_mod;

typedef struct s_coords
{
	int				startx;
	int				starty;
	int				endx;
	int				endy;
	int				color;
	int				alt;
	int				linelen;
}				t_coords;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				llen;
	int				en;
}				t_img;

typedef struct s_map
{
	int			**map;
	int			width;
	int			height;
	int			diff;
	int			x;
	int			y;
}				t_map;

typedef struct s_bres
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	stepy;
	int	stepx;
	int	error;
	int	e2;
}				t_bres;

typedef struct s_mlxinfo
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_mod			mod;
	t_map			*map;
	t_coords		*coords;
	void			*currentimg;
}				t_mlxinfo;

//fdf.c
void	modhandler(int keycode, t_mlxinfo *mlx);
int		key_hook(int keycode, t_mlxinfo *mlxinfo);
int		dimensioninit(t_map *map, char **av);
int		freeandexit(t_mlxinfo *mlx);
int		main(int ac, char **av);

//fdf_utils.c
void	modinit(t_mlxinfo *mlx);
void	hookinit(t_mlxinfo *mlx, t_coords *coords, t_map *map, t_img *img);
void	freemap(t_map map);
void	justadot(t_img *img, t_map map);

//coords_utils.c
void	scaler(t_map *map, t_coords *coords, int i, t_mlxinfo *mod);
void	shiftplane(t_coords *coords, t_map map);
void	shiftplanedown(t_coords *coords, t_map map);

//createmap.c
int		getheight(char **av);
int		getwidth(char **av);
int		getmaparr(t_map *map);
void	fillhelper(int y, t_map *map, char **temp);
int		createmap(t_map *map, char **av, int y);

//draw.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	drawinit(t_bres *bres, t_coords *coords);
void	drawl(t_img *img, t_coords *coords, int color);
void	advancehelper(t_map *map, int i);
void	drawgrid(t_map map, t_img *img, t_coords *coords, t_mlxinfo *mlx);

//coords.c
void	getcoords(t_coords *coords, t_map map);
void	getcoordsdown(t_coords *coords, t_map map);
void	getcoordsrow(t_coords *coords, t_map map, int i);
void	getcoordscol(t_coords *coords, t_map map, int i);

#endif
