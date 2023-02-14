/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:41:02 by aconde-m          #+#    #+#             */
/*   Updated: 2022/04/26 12:37:12 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		cont;
	char		*ret;

	ret = (char *)dst;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		cont = 0;
		while (cont < n)
		{
			*(char *)(dst + cont) = *(char *)(src + cont);
			cont++;
		}
	}
	else
	{
		while (n--)
			*(char *)(dst + n) = *(char *)(src + n);
	}
	return (ret);
}
