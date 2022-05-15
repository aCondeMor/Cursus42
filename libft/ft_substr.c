/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:32:51 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/15 23:15:58 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	init;
	char	*newstr;

	i = 0;
	init = (size_t)start;
	if (!s)
		return (0);
	newstr = malloc(len + 1);
	if (!(newstr))
		return (0);
	if ((ft_strlen(s) < (int)start))
		return (ft_strdup(""));
	while ((s[init + i] != '\0') && (i < len))
	{
		newstr[i] = s[init + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
