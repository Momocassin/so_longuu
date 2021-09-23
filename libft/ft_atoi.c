/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:20:36 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:09:16 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	x;
	int	y;
	int	signe;

	x = 0;
	y = 0;
	signe = 1;
	while (str[x] == ' ' || str[x] == '\f' || str[x] == '\t' || str[x] == '\v'
			|| str[x] == '\n' || str[x] == '\r')
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			signe = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		y = (y * 10) + (str[x] - '0');
		x++;
	}
	return (y * signe);
}
