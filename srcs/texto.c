/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:30:22 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:30:23 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	texture_start(t_texture *texture, t_mlx *mlx, t_every *info)
{
	texture->diam.ptr = mlx_xpm_file_to_image(mlx->mlx, "img/diamond.xpm",
			&texture->diam.width, &texture->diam.height);
	texture->boug.ptr = mlx_xpm_file_to_image(mlx->mlx, "img/boug.xpm",
			&texture->boug.width, &texture->boug.height);
	texture->sol.ptr = mlx_xpm_file_to_image(mlx->mlx, "img/sol.xpm",
			&texture->sol.width, &texture->sol.height);
	texture->pip.ptr = mlx_xpm_file_to_image(mlx->mlx, "img/pip.xpm",
			&texture->pip.width, &texture->pip.height);
	texture->mur.ptr = mlx_xpm_file_to_image(mlx->mlx, "img/mur.xpm",
			&texture->mur.width, &texture->mur.height);
	if (texture->diam.ptr == NULL || texture->boug.ptr == NULL
		|| texture->sol.ptr == NULL || texture->pip.ptr == NULL
		|| texture->mur.ptr == NULL)
		free_mem(info, "Error\nError while allocating memory5\n", 3);
	texture->diam.add = mlx_get_data_addr(texture->diam.ptr,
			&texture->diam.bpp, &texture->diam.line, &texture->diam.endian);
	texture->boug.add = mlx_get_data_addr(texture->boug.ptr,
			&texture->boug.bpp, &texture->boug.line, &texture->boug.endian);
	texture->sol.add = mlx_get_data_addr(texture->sol.ptr,
			&texture->sol.bpp, &texture->sol.line,
			&texture->sol.endian);
	texture->pip.add = mlx_get_data_addr(texture->pip.ptr,
			&texture->pip.bpp, &texture->pip.line, &texture->pip.endian);
	texture->mur.add = mlx_get_data_addr(texture->mur.ptr,
			&texture->mur.bpp, &texture->mur.line, &texture->mur.endian);
}
