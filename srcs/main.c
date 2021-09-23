/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:18:19 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/22 00:23:11 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	erroruu(char *str)
{
	write(1, "[so_long] ", 10);
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

static t_every	*inito_no(void)
{
	t_every		*info;

	info = malloc(sizeof(t_every) * 1);
	if (info == NULL)
		erroruu("Error\nError while allocating memory");
	info->mlx = malloc(sizeof(t_mlx) * 1);
	info->texture = malloc(sizeof(t_texture) * 1);
	info->key = malloc(sizeof(t_key) * 1);
	info->map = malloc(sizeof(t_map) * 1);
	if (info->key == NULL || info->mlx == NULL || info->texture == NULL
		|| info->map == NULL)
		free_mem(info, "Error\nError while allocating memory", 0);
	return (info);
}

int	main(int argc, char **argv)
{
	t_every		*info;

	if (argc != 2)
		erroruu("Error\nYou need 2 arguments.\n");
	else
	{
		info = inito_no();
		info->map = mapuu(argv, info->map, info);
		info->mlx->mlx = mlx_init();
		info->mlx->mlx_win = mlx_new_window(info->mlx->mlx,
				(info->map->lenght * 32),
				(info->map->width * 32), "So Long");
		texture_start(info->texture, info->mlx, info);
		renderuu(info->texture, info->map, info->mlx, info);
		info->key->nbr_press = 0;
		mlx_do_key_autorepeatoff(info->mlx->mlx);
		mlx_hook(info->mlx->mlx_win, 2, 1L << 0, ipod_touche, info);
		mlx_hook(info->mlx->mlx_win, 17, 1L << 17, mlx_terminator, info);
		mlx_loop_hook(info->mlx->mlx, updatuu, info);
		mlx_loop(info->mlx->mlx);
		return (0);
	}
}
