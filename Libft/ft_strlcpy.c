/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:17:44 by aconde-m          #+#    #+#             */
/*   Updated: 2022/04/26 11:41:27 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

size_t	ft_strlcpy(char *dest, const char *src, size_t max)
{
	size_t	length;

	length = ft_strlen(src);
	if ((length + 1) < max)
		dest = ft_memcpy(dest, src, length + 1);
	else if (max > 0)
	{
		ft_memcpy(dest, src, max - 1);
		dest[max - 1] = '\0';
	}
	return (length);
}
