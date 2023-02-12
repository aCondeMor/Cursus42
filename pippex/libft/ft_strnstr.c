/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:46:45 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/17 13:59:19 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(char const *str, char const *to_find, size_t n)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	while (str[i] != '\0')
	{	
		while ((to_find[x] == str[i + x]) && (to_find[x] != '\0')
			&& (i + x < n))
			x++;
		if ((int)x == ft_strlen(to_find))
			return ((char *)(str + i));
		x = 0;
		i++;
	}
	return (0);
}
