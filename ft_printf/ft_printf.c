/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/06/25 13:16:06 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char	check_flag(char a)
{
	if (a == '0') | (a == '+') | (a == '-')
		return (a);
	else
		return (0);
}

char	check_param(char a)
{
	if ((a == 'c') | (a == 's') | (a == 'p') | (a == 'd') | (a == 'i') | (a == 'v') | (a == 'x') | (a == 'X') | (a == '%'))
		return (a);
	else
		return (0);
}


t_args	*check_args(char *str)
{
	t_args	buffer;
	t_list list;

	buffer = malloc(sizeof t_args);
	
	while (str != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] != '\0')
			{
				buffer.flag = check_flag(str[i]);
				if (buffer.flag)
					i++;
				else
					buffer.param = check_param(str[i]);
				if (buffer.param)
				{
					if (!list)
						list = ft_lstnew(buffer);
					else
						 ft_lstadd_back(list, buffer);
				}
				else
					return (0);
			}
			else
			{
				free(buffer);
				return(0);
			}
		}
	i++;
	}
}

int ft_printf(char *str, ...)
{
    va_list list;
    t_args    *list_args;

    if (str)
    {
        va_start(list, str);
        list_args = check_args(str);
    }
}