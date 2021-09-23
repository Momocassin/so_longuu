/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:17:02 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 01:53:23 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_img
{
	void	*ptr;
	char	*add;
	int		bpp;
	int		line;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_texture
{
	t_img	sol;
	t_img	diam;
	t_img	boug;
	t_img	pip;
	t_img	mur;

}				t_texture;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;

}				t_mlx;

typedef struct s_posi
{
	int		status;
	int		X;
	int		Y;

}				t_posi;

typedef struct s_map
{
	char	*map_string;
	char	**map;
	int		lenght;
	int		width;
	int		collec;
	int		exit;
	t_posi	*collec_pos;
	t_posi	*exit_pos;
	t_posi	player;
}				t_map;

typedef struct s_coo
{
	int		n;
	int		i;
	int		X;
	int		Y;
	int		coll;
	int		exi;
}				t_coo;

typedef struct s_key
{
	int		W;
	int		A;
	int		S;
	int		D;
	int		ESC;
	int		nbr_press;
}				t_key;

typedef struct s_every
{
	t_map		*map;
	t_texture	*texture;
	t_mlx		*mlx;
	t_key		*key;
}				t_every;


t_map	*mapuu(char **argv, t_map *map, t_every *info);
int		finito_pipo(char *str, char *to_find);
int		map_copy(char *path, t_map *map, t_every *info);
int		check_mapuu(t_map *map, t_every *info);
int		error_in_parse(t_map *map);
void	erroruu(char *str);
void	free_mem(t_every *info, char *str, int stage);
void	texture_start(t_texture *texture, t_mlx *mlx, t_every *info);
void	renderuu(t_texture *texture, t_map *map, t_mlx *mlx,
			t_every *info);
int		updatuu(t_every *info);
void	maison_blanche(t_texture *texture, t_map *map, t_mlx *mlx,
			t_every *info);
int		ipod_touche(int keycode, t_every *info);
int		mlx_terminator(t_every *info);

#endif
