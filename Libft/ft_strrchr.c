/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:56:26 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/04 11:57:43 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strrchr(char *src, int c)
{
	size_t	length_src;
	size_t count;
	char	*aux;

	length_src = ft_strlen(src);
	count = 0;
	aux = NULL;
	while (count <= length_src)
	{
		if (src[count] == c)
			aux = (src + count);
		count++;
	}
	return (aux);
}
