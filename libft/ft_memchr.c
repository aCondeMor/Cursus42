/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:59:18 by aconde-m          #+#    #+#             */
/*   Updated: 2022/04/28 11:53:04 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *dst, int c, size_t n)
{
	size_t		cont;

	cont = 0;
	while (cont < n)
	{
		if (*(unsigned char *)(dst + cont) == (unsigned char)c)
			return (dst + cont);
		else
			cont++;
	}
	return (NULL);
}
