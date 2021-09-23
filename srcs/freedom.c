/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:29:33 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:29:34 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_map(t_map *map, int stage)
{
	int	i;

	i = 0;
	if (stage >= 1)
	{
		if (map->map_string)
			free(map->map_string);
		if (map->map)
		{
			while (map->map[i])
			{
				free(map->map[i]);
				i++;
			}
			free(map->map);
		}
		if (stage >= 2)
		{
			if (map->collec_pos)
				free(map->collec_pos);
			if (map->exit_pos)
				free(map->exit_pos);
		}
	}
}

static void	free_texture(t_every *info, t_texture *texture)
{
	if (texture->diam.ptr)
		mlx_destroy_image(info->mlx->mlx, texture->diam.ptr);
	if (texture->boug.ptr)
		mlx_destroy_image(info->mlx->mlx, texture->boug.ptr);
	if (texture->sol.ptr)
		mlx_destroy_image(info->mlx->mlx, texture->sol.ptr);
	if (texture->pip.ptr)
		mlx_destroy_image(info->mlx->mlx, texture->pip.ptr);
	if (texture->mur.ptr)
		mlx_destroy_image(info->mlx->mlx, texture->mur.ptr);
	if (info->mlx->mlx_win)
		mlx_destroy_window(info->mlx->mlx, info->mlx->mlx_win);
	if (info->mlx->mlx)
		free(info->mlx->mlx);
}

void	free_mem(t_every *info, char *str, int stage)
{
	if (stage >= 1)
	{
		free_map(info->map, stage);
		if (stage >= 3)
			free_texture(info, info->texture);
	}
	free(info->key);
	free(info->mlx);
	free(info->map);
	free(info->texture);
	free(info);
	if (stage < 4)
		erroruu(str);
	else
		exit(EXIT_SUCCESS);
}
