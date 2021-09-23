/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:56:55 by motaouss          #+#    #+#             */
/*   Updated: 2020/01/11 10:05:18 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;

	if (!(tab = malloc(size * nmemb)))
		return (NULL);
	ft_memset(tab, 0, nmemb);
	return (tab);
}
