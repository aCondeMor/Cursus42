/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:05:24 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/04 16:26:35 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*newstr;
	
	if ((count == SIZE_MAX && size > 1) || (count > 1 && size == SIZE_MAX))
		return (NULL);
	newstr = malloc(count * size);
	if (!newstr)
		return(NULL);
	ft_bzero(newstr, size * count);
	return(newstr);
}
