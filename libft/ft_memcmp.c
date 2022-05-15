/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:09:25 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/15 23:30:37 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *dst, void *src, size_t n)
{
	size_t			cont;
	unsigned char	*dstcpy;
	unsigned char	*srccpy;

	cont = 0;
	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	while (cont < n)
	{
		if (*(dstcpy + cont) != *(srccpy + cont))
			return (*(dstcpy + cont) - *(srccpy + cont));
		cont++;
	}
	return (0);
}
