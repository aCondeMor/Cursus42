/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 00:38:18 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/15 22:57:34 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	if (!s || !f)
		return (0);
	newstr = ft_strdup(s);
	if (!newstr)
		return (0);
	i = 0;
	while (newstr[i] != '\0')
	{
		newstr[i] = f(i, newstr[i]);
		i++;
	}
	return (newstr);
}
