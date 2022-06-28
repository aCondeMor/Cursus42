/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/06/28 16:46:20 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(char a, va_list list)
{
	if (a == 'c')
		return (ft_print_char(list));
	else if (a == 's')
		return (ft_print_str(list));
	else if (a == 'p')
		return (ft_print_hexa(list));
	/*else if (a == 'd')
	else if (a == 'i')
	else if (a == 'v')
	else if (a == 'x')
	else if (a == 'X')
	else if (a == '%')*/
	else
		return (0);
}

int	ft_printf(char *str, ...)
{
	va_list	list;
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	if (str)
	{
		va_start(list, str);
		while (str[i] != '\0')
		{
			if (str[i] == '%')
			{
				i++;
				sum += ft_print_arg(str[i], list);
			}
			else
				write(1, &str[i], 1);
		i++;
		sum++;
		}
	}
	va_end(list);
	return (sum);//chequear si cuenta los salto de linea y el fin de fichero al terminar
}
