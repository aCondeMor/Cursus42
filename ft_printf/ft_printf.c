/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/06/22 17:35:54 by aconde-m         ###   ########.fr       */
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
	//modificarlo para hacerlo con una lista
	t_args	*args;
	t_args	buffer;

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
					args = add_buffer(args, buffer); //esto deberías hacerlo con una lista
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