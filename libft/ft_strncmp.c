/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:08:30 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/15 23:36:21 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *dst, char *src, size_t n)
{
	size_t			count;
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	count = 0;
	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	while (count < n)
	{
		if ((dst[count] == '\0') && (src[count] == dst[count]))
			return (0);
		if (*(dst + count) != *(src + count))
			return ((*(dst_cpy + count) - *(src_cpy + count)));
		count++;
	}
	return (0);
}
