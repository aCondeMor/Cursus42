/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:35:12 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/15 23:32:07 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strchr(char *src, int c)
{
	size_t	length_src;
	size_t	count;

	length_src = ft_strlen(src);
	count = 0;
	while (count <= length_src)
	{
		if (src[count] == c)
			return (src + count);
		count++;
	}
	return (NULL);
}
