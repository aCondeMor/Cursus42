/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:35:12 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/17 12:43:13 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strchr(char *src, int c)
{
	unsigned int	length_src;
	unsigned int	count;

	length_src = ft_strlen(src);
	count = 0;
	while (count <= length_src)
	{
		if (src[count] == (unsigned char)(c))
			return (src + count);
		count++;
	}
	return (NULL);
}
