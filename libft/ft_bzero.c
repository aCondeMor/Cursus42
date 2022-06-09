/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:36:08 by aconde-m          #+#    #+#             */
/*   Updated: 2022/06/09 12:23:09 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t n)
{
	size_t		cont;

	cont = 0;
	while (cont < n)
	{
		*(unsigned char *)(str + cont) = '\0';
		cont++;
	}
	return (str);
}
