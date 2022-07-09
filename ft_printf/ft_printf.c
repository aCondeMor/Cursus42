/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/07/09 10:06:33 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(char a, va_list list)
{
	if (a == 'c')
		return (ft_print_char(va_arg(list, int)));
	else if (a == 's')
		return (ft_print_str(va_arg(list, char *)));
	else if (a == 'p')
		return (ft_print_hexa(va_arg(list, unsigned long long)));
	else if (a == 'd')
		return (ft_newitoa(va_arg(list, int)));
	else if (a == 'i')
		return (ft_newitoa(va_arg(list, int)));
	else if (a == 'u')
		return (ft_newutoa((int)va_arg(list, unsigned int)));
	else if (a == 'x')
		return (ft_print_xhexa(va_arg(list, unsigned int)));
	else if (a == 'X')
		return (ft_print_x_may_hexa(va_arg(list, unsigned int)));
	else if (a == '%')
	{
		write(1, &a, 1);
		return (1);
	}
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		sum;
	int		found;

	found = 0;
	i = 0;
	sum = 0;
	va_start(list, str);
	if (str)
	{
		while (str[i] != '\0')
		{
			if (str[i] == '%')
				sum += ft_print_arg(str[i++ + 1], list) - 1;
			else
				write(1, &str[i], 1);
		i++;
		sum++;
		}
	}
	va_end(list);
	return (sum);
}
