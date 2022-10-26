/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:39:15 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/15 22:52:02 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		length_s1;
	int		i;
	int		j;

	if (!s1)
		return (0);
	length_s1 = ft_strlen(s1);
	i = 0;
	while ((s1[i] != '\0') && ft_strchr((char *)set, s1[i]) && set)
		i++;
	j = length_s1;
	while ((j > i) && set && ft_strchr((char *)set, s1[j - 1]))
		j--;
	return (ft_substr(s1, i, j - i));
}
