/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:18:39 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:05:01 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	change_map(int Y, int X, t_every *info)
{
	int	posx;
	int	posy;

	posx = info->map->player.X;
	posy = info->map->player.Y;
	info->map->map[Y][X] = 'P';
	info->map->map[posy][posx] = '0';
	info->map->player.Y = Y;
	info->map->player.X = X;
	info->key->nbr_press += 1;
	printf("current number of movements : %d\n", info->key->nbr_press);
}

static int	check_event(t_every *info, int X, int Y, char **map)
{
	int	i;

	i = 0;
	if (map[Y][X] == 'C')
	{
		while (i < info->map->collec)
		{
			if (Y == info->map->collec_pos[i].Y
				&& X == info->map->collec_pos[i].X)
				info->map->collec_pos[i].status = 0;
			i++;
		}
	}
	else if (map[Y][X] == 'E')
	{
		while (i < info->map->collec)
		{
			if (info->map->collec_pos[i].status == 1)
				return (1);
			i++;
		}
		free_mem(info, "win", 4);
	}
	return (0);
}

static void	deplacement_hin(t_every *info, int posy, int posx)
{
	if (info->key->A == 1)
	{
		if (check_event(info, posx - 1, posy, info->map->map) == 0
			&& info->map->map[posy][posx - 1] != '1')
			change_map(posy, posx - 1, info);
		info->key->A = 0;
	}
	else if (info->key->D == 1)
	{
		if (check_event(info, posx + 1, posy, info->map->map) == 0
			&& info->map->map[posy][posx + 1] != '1')
			change_map(posy, posx + 1, info);
		info->key->D = 0;
	}
}

static void	deplacement_1(t_every *info, int posx, int posy)
{
	if (info->key->W == 1)
	{
		if (check_event(info, posx, posy - 1, info->map->map) == 0
			&& info->map->map[posy - 1][posx] != '1')
			change_map(posy - 1, posx, info);
		info->key->W = 0;
	}
	else if (info->key->S == 1)
	{
		if (check_event(info, posx, posy + 1, info->map->map) == 0
			&& info->map->map[posy + 1][posx] != '1')
			change_map(posy + 1, posx, info);
		info->key->S = 0;
	}
	else
		deplacement_hin(info, posy, posx);
}

int	updatuu(t_every *info)
{
	deplacement_1(info, info->map->player.X, info->map->player.Y);
	maison_blanche(info->texture, info->map, info->mlx, info);
	return (0);
}
