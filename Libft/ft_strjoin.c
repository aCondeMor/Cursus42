/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:06:40 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/11 12:42:44 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		length_s1;
	int		length_s2;
	int		i;
	int		j;
	char	*s3;
	if (!s1 || !s2)
		return (0);	
	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s2);
	i = 0;
	s3 = malloc(length_s1 + length_s2 + 1);
	if (!s3)
		return (0);
	while (s1[i] != '\0')
	{	
		s3[i] = s1[i];	
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}
