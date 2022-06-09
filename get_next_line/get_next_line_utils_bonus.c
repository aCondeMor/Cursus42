/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:47:42 by aconde-m          #+#    #+#             */
/*   Updated: 2022/06/09 18:14:34 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t		cont;

	cont = 0;
	if (!dst && !src)
		return (NULL);
	while (cont < n)
	{
		*(unsigned char *)(dst + cont) = *(unsigned char *)(src + cont);
		cont++;
	}
	return (dst);
}

char	*ft_strdup(char *str)
{
	char	*newstr;

	newstr = malloc(ft_strlen(str) + 1);
	if (!newstr)
		return (0);
	newstr = ft_memcpy(newstr, str, ft_strlen(str) + 1);
	return (newstr);
}

char	*ft_strchr(char *src, int c)
{
	unsigned int	length_src;
	unsigned int	count;

	if (!src)
		return (NULL);
	length_src = ft_strlen(src);
	count = 0;
	while (count <= length_src)
	{
		if (src[count] == (unsigned char)(c))
			return (src + count);
		count++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		length_s1;
	int		length_s2;
	int		i;
	int		j;
	char	*s3;

	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s2);
	i = 0;
	s3 = malloc(length_s1 + length_s2 + 1);
	if (!s3)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
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
