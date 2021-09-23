/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:17:35 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 01:43:39 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_charuu(char *map_file)
{
	int		fd;
	char	buff;
	int		i;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((read(fd, &buff, 1)))
		i++;
	close(fd);
	return (i);
}

static int	*copy(char *res, char *map_file)
{
	int		fd;
	char	buff;
	int		i;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((read(fd, &buff, 1)))
	{
		res[i] = buff;
		i++;
	}
	res[i] = '\0';
	close(fd);
	return (0);
}

int	map_copy(char *path, t_map *map, t_every *info)
{
	map->map_string = malloc(sizeof(char) * count_charuu(path) + 1);
	if (map->map_string == NULL)
		free_mem(info, "Error\nError while allocating memory2", 0);
	copy(map->map_string, path);
	map->map = ft_split(map->map_string, '\n');
	if (map->map == NULL)
	{
		free(map->map_string);
		free_mem(info, "Error\nError while allocating memory3", 0);
	}
	return (1);
}
