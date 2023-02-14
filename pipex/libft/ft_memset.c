/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:02:25 by aconde-m          #+#    #+#             */
/*   Updated: 2022/04/26 12:39:05 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t		cont;

	cont = 0;
	while (cont < n)
	{
		*(unsigned char *)(str + cont) = (unsigned char)c;
		cont++;
	}
	return (str);
}
