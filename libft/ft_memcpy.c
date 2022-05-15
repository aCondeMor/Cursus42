/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:59:18 by aconde-m          #+#    #+#             */
/*   Updated: 2022/04/26 12:37:56 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		cont;

	cont = 0;
	if (!dst && !src)
		return (NULL);
	while (cont < n)
	{
		*(unsigned char *)(dst + cont) = *(unsigned char *)(src + cont);
		cont++;
	}
	return (dst);
}
