/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:56:16 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/02/23 18:36:23 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	getheight(char **av)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

int	getwidth(char **av)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**temp;

	i = 0;
	j = 0;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	close(fd);
	temp = ft_split(line, ' ');
	free(line);
	while (temp[i] && *temp[i] != '\n')
		i++;
	while (temp[j])
	{
		free(temp[j]);
		j++;
	}
	free(temp);
	return (i);
}

int	getmaparr(t_map *map)
{
	int	x;

	x = 0;
	map->map = (int **)malloc(sizeof(int *) * map->height);
	if (map->map == NULL)
		return (1);
	while (x < map->height)
	{
		map->map[x] = (int *)malloc(sizeof(int) * map->width);
		if (map->map[x] == NULL)
			return (1);
		x++;
	}
	return (0);
}

void	fillhelper(int y, t_map *map, char **temp)
{
	int	x;

	x = 0;
	while (x < map->width)
	{
		map->map[y][x] = ft_atoi(temp[x]);
		x++;
	}
	x = 0;
	while (temp[x])
	{
		free(temp[x]);
		x++;
	}
	free(temp);
}

int	createmap(t_map *map, char **av, int y)
{
	char	*line;
	char	**temp;
	int		fd;

	fd = open(av[1], O_RDONLY, 0666);
	if (getmaparr(map) == 1)
		return (1);
	while (y < map->height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (1);
		temp = ft_split(line, ' ');
		if (temp == NULL)
		{
			freemap(*map);
			return (1);
		}
		free(line);
		fillhelper(y, map, temp);
		y++;
	}
	close(fd);
	return (0);
}
