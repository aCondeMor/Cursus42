/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:13:33 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/11 18:43:58 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int ft_count_lines(char const *s, char c)
{
	int i;
	int x;
	int	count;

	i = 0;
	x = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (count == 0))
		{
		 	x++;
			count = 1;
		}
		else if (s[i] == c)
			count = 0;
		i++;
	}
	return (x);
}

char	**ft_split(char const *s, char c)
{
	int 	i;
	int 	j;
	int 	z;
	char	**new_str;

	if (!s)
		return (0);
	i = 0;
	j = -1;
	z = 0;
	new_str = malloc(sizeof(char *) * (ft_count_lines(s,c) + 1));
	if (!new_str)
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && j < 0)
			j = i;
		else if ((s[i] == c || i == ft_strlen(s)) && j >= 0)
		{
			new_str[z++] = ft_substr(s, j, (i-j));
			j = -1;
		}
		i++;
	}
	new_str[z] = 0;
	return (new_str);
}
