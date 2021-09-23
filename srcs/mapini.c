/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapini.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:30:06 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:30:07 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	checkuu(char *name, t_every *info)
{
	int		i;
	int		fd;
	char	buf;

	i = 0;
	while (name[i] && name[i] != '.')
		i++;
	if (name[i] == '\0')
		free_mem(info, "Error\nThe file extension is not a .ber\n", 0);
	if (finito_pipo(name, ".ber") == 1)
	{
		fd = open(name, O_RDONLY);
		if (fd == -1)
			free_mem(info, "Error\nWrong map path or the map doesn't exist\n", 0);
		if (read(fd, &buf, 1) == -1)
			free_mem(info, "Error\nThe map is a directory\n", 0);
		close(fd);
		return (1);
	}
	free_mem(info, "Error\nThe file extension is not .ber\n", 0);
	exit(EXIT_FAILURE);
}

static int	map_checkuu(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_string[i] != '\0')
	{
		if (map->map_string[i] != '\n' && map->map_string[i] != '0'
			&& map->map_string[i] != '1' && map->map_string[i] != 'P'
			&& map->map_string[i] != 'E' && map->map_string[i] != 'C')
			return (-1);
		i++;
	}
	return (0);
}

static int	map_gelar(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_string[i] != '\0')
	{
		if (map->map_string[i] == '\n')
			map->width++;
		i++;
	}
	if (map->map_string[i - 1] == '1')
		map->width++;
	else
		return (-1);
	return (0);
}

static int	map_size(t_map *map)
{
	int	x;
	int	y;
	int	prev;

	prev = 0;
	x = 0;
	y = 0;
	if (map_gelar(map) == -1)
		return (-2);
	while (y < map->width)
	{
		x = 0;
		while (map->map[y][x])
			x++;
		if (x != prev && prev != 0)
			return (-1);
		prev = x;
		y++;
	}
	map->lenght = prev;
	return (1);
}

t_map	*mapuu(char **argv, t_map *map, t_every *info)
{
	int	x;

	map->lenght = 0;
	map->width = 0;
	map->collec = 0;
	map->exit = 0;
	map->player.status = 0;
	checkuu(argv[1], info);
	map_copy(argv[1], map, info);
	if (map_checkuu(map) == -1)
		free_mem(info, "Error\nThe map contain un unknown letter\n", 1);
	x = map_size(map);
	if (x == -1)
		free_mem(info, "Error\nThe map is not a rectangle\n", 1);
	else if (x == -2)
		free_mem(info, "Error\nNewline at the end of the map\n", 1);
	check_mapuu(map, info);
	map->collec_pos = malloc(sizeof(t_posi) * map->collec);
	map->exit_pos = malloc(sizeof(t_posi) * map->exit);
	if (map->collec_pos == NULL || map->exit_pos == NULL)
		free_mem(info, "Error\nError while allocating memory1", 2);
	return (map);
}
