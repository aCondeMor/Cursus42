/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/06/28 17:24:05 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list list)
{
	ft_putchar_fd(va_arg(list, int), 1);
	return (1);
}

int	ft_print_str(va_list list)
{
	char	*word;

	word = va_arg(list, char *);
	ft_putstr_fd(word, 1);
	return (ft_strlen(word));
}

int	ft_print_hexa(va_list list) //buscarlo en la piscina C04/EX04
{
	unsigned long long	hexadec;

	hexadec = va_arg(list, unsigned long long);

	return (1 + a);
}
