/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:09:25 by aconde-m          #+#    #+#             */
/*   Updated: 2022/04/28 12:16:00 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *dst, void *src, size_t n)
{
	size_t		cont;
	
	cont = 0;
	while (cont < n)
	{
		if (*(char *)(dst + cont) != *(char *)(src + cont))
			return (*(char *)(dst + cont) - *(char *)(src + cont));
		else
			cont++;
	}
	return (0);
}
