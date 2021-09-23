/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:19:08 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/21 23:57:12 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	finito_pipo(char *str, char *to_find)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == to_find[n] && to_find[n])
		{
			i++;
			n++;
		}
		if (to_find[n] == '\0' && str[i] == '\0')
			return (1);
		else
		{
			i = i - n;
			n = 0;
		}
		i++;
	}
	return (0);
}
