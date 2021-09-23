/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 01:59:52 by motaouss          #+#    #+#             */
/*   Updated: 2019/06/27 02:21:47 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lengths(int n, size_t *x, int *z)
{
	*x = 1;
	if (n >= 0)
	{
		*x = 0;
		n = -n;
	}
	*z = 1;
	while (n / *z < -9)
	{
		*z *= 10;
		*x += 1;
	}
}

char		*ft_itoa(int n)
{
	char	*s;
	size_t	x;
	size_t	y;
	int		z;

	lengths(n, &x, &z);
	if (!(s = (char *)malloc(sizeof(char) * (x + 2))))
		return (NULL);
	y = 0;
	if (n < 0)
	{
		s[y] = '-';
		y++;
	}
	if (n > 0)
		n = -n;
	while (z >= 1)
	{
		s[y++] = -(n / z % 10) + 48;
		z /= 10;
	}
	s[y] = '\0';
	return (s);
}
