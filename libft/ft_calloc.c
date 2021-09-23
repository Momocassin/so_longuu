/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:17:51 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/23 17:17:53 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*re;
	char	*str;
	size_t	i;

	i = 0;
	re = malloc(size * count);
	if (re == NULL)
		return (NULL);
	str = (char *)re;
	while (i <= size * count)
	{
		str[i] = '\0';
		i++;
	}
	return (re);
}
