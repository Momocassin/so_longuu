/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eren_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:29:27 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:29:29 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	startuu_dist(t_map *map, t_coo *coo)
{
	if (map->map[coo->n][coo->i] == 'P')
	{
		map->player.X = coo->X / 32;
		map->player.Y = coo->Y / 32;
	}
	else if (map->map[coo->n][coo->i] == 'E')
	{
		map->exit_pos[coo->exi].X = coo->X / 32;
		map->exit_pos[coo->exi].Y = coo->Y / 32;
		map->exit_pos[coo->exi].status = 1;
		coo->exi += 1;
	}
	else if (map->map[coo->n][coo->i] == 'C')
	{
		map->collec_pos[coo->coll].X = coo->X / 32;
		map->collec_pos[coo->coll].Y = coo->Y / 32;
		map->collec_pos[coo->coll].status = 1;
		coo->coll += 1;
	}
}

static void	putoo_dist(t_texture *texture, t_map *map, t_mlx *mlx,
	t_coo *coo)
{
	if (map->map[coo->n][coo->i] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->mur.ptr, coo->X, coo->Y);
	else if (map->map[coo->n][coo->i] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->sol.ptr, coo->X, coo->Y);
	else if (map->map[coo->n][coo->i] == 'P')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->boug.ptr, coo->X, coo->Y);
		startuu_dist(map, coo);
	}
	else if (map->map[coo->n][coo->i] == 'E')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->pip.ptr, coo->X, coo->Y);
		startuu_dist(map, coo);
	}
	else if (map->map[coo->n][coo->i] == 'C')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->diam.ptr, coo->X, coo->Y);
		startuu_dist(map, coo);
	}
}

void	renderuu(t_texture *texture, t_map *map, t_mlx *mlx,
	t_every *info)
{
	t_coo	*coo;

	coo = malloc(sizeof(t_coo) * 1);
	if (coo == NULL)
		free_mem(info, "Error\nError while allocating memory4\n", 3);
	coo->i = 0;
	coo->n = 0;
	coo->X = 0;
	coo->Y = 0;
	coo->coll = 0;
	coo->exi = 0;
	while (map->map[coo->n])
	{
		while (map->map[coo->n][coo->i])
		{
			putoo_dist(texture, map, mlx, coo);
			coo->i++;
			coo->X = coo->X + 32;
		}
		coo->n++;
		coo->i = 0;
		coo->X = 0;
		coo->Y = coo->Y + 32;
	}
	free(coo);
}
