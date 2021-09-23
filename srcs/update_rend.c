/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:18:58 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/22 00:07:09 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	kech_mara(t_texture *texture, t_map *map, t_mlx *mlx,
	t_coo *coo)
{
	if (map->map[coo->n][coo->i] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->mur.ptr, coo->X, coo->Y);
	else if (map->map[coo->n][coo->i] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->sol.ptr, coo->X, coo->Y);
	else if (map->map[coo->n][coo->i] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->boug.ptr, coo->X, coo->Y);
	else if (map->map[coo->n][coo->i] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->pip.ptr, coo->X, coo->Y);
	else if (map->map[coo->n][coo->i] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->diam.ptr, coo->X, coo->Y);
}

void	maison_blanche(t_texture *texture, t_map *map, t_mlx *mlx,
	t_every *info)
{
	t_coo	*coo;

	coo = malloc(sizeof(t_coo) * 1);
	if (coo == NULL)
		free_mem(info, "Error\nError while allocating memory6\n", 3);
	coo->i = 0;
	coo->n = 0;
	coo->X = 0;
	coo->Y = 0;
	while (map->map[coo->n])
	{
		while (map->map[coo->n][coo->i])
		{
			kech_mara(texture, map, mlx, coo);
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
