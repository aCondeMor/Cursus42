/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:35:12 by aconde-m          #+#    #+#             */
/*   Updated: 2023/02/13 15:23:51 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strchr(char *src, int c)
{
	unsigned int	length_src;
	unsigned int	count;

	if (!src)
		return (NULL);
	length_src = ft_strlen(src);
	count = 0;
	while (count < length_src)
	{
		if (src[count] == (unsigned char)(c))
			return (src + count);
		count++;
	}
	return (NULL);
}
