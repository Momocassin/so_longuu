/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:29:22 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:29:23 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_letters(t_map *map, int cpy_width, int i)
{
	if ((cpy_width == map->width || cpy_width == 0)
		&& map->map[cpy_width][i] != '1')
		return (-1);
	else if ((i == 0 || i == map->lenght - 1)
		&& map->map[cpy_width][i] != '1')
		return (-1);
	else if (map->map[cpy_width][i] == 'C')
		map->collec++;
	else if (map->map[cpy_width][i] == 'E')
		map->exit++;
	else if (map->map[cpy_width][i] == 'P')
	{
		if (map->player.status == 1)
			map->map[cpy_width][i] = '0';
		else
			map->player.status++;
	}
	else if (map->map[cpy_width][i] == '0' || map->map[cpy_width][i] == '1')
		return (0);
	else
		return (-1);
	return (0);
}

int	check_mapuu(t_map *map, t_every *info)
{
	int	cpy_width;
	int	i;

	cpy_width = map->width - 1;
	while (cpy_width != -1)
	{
		i = 0;
		while (map->map[cpy_width][i])
		{
			if (check_letters(map, cpy_width, i) == -1)
				free_mem(info, "Error\nYour map is invalid\n", 1);
			i++;
		}
		cpy_width--;
	}
	if (map->collec != 0 && map->exit != 0 && map->player.status != 0)
		return (1);
	else
		free_mem(info, "Error\nYour map is missing an obligatory letter\n", 1);
	return (0);
}
