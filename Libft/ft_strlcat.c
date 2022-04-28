/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:00:56 by aconde-m          #+#    #+#             */
/*   Updated: 2022/04/28 11:52:29 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

size_t	ft_strlcat(char *dest, const char *src, size_t max)
{
	size_t	length_src;
	size_t	length_dest;

	length_src = ft_strlen(src);
	length_dest = ft_strlen(dest);
	if (max > length_dest)
	{
		ft_memcpy((dest + length_dest), src, max - length_dest - 1);
		dest[max - 1] = '\0';
		return (length_dest + length_src);
	}
	else
		return (ft_strlen(src) + max);
}
