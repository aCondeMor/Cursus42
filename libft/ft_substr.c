/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:32:51 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/17 17:33:43 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*newstr;

	i = 0;
	if (!s)
		return (0);
	if (((unsigned int)ft_strlen(s) < start))
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) > len)
		newstr = malloc((len + 1) * sizeof(char));
	else
		newstr = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	if (!(newstr))
		return (0);
	while (s[start + i] && (i < len))
	{
		newstr[i] = s[(size_t)start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
