/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 03:32:09 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:11:30 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
