/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 03:32:09 by motaouss          #+#    #+#             */
/*   Updated: 2019/06/25 03:06:48 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t x;

	x = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)s1)[x] == ((unsigned char *)s2)[x]
			&& ((unsigned char *)s1)[x]
			&& ((unsigned char *)s2)[x] && x < (n - 1))
		x++;
	return (((unsigned char *)s1)[x] - ((unsigned char *)s2)[x]);
}
