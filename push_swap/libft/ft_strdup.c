/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:45:13 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/15 23:02:53 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *str)
{
	char	*newstr;

	newstr = malloc(ft_strlen(str) + 1);
	if (!newstr)
		return (0);
	newstr = ft_memcpy(newstr, str, ft_strlen(str) + 1);
	return (newstr);
}
