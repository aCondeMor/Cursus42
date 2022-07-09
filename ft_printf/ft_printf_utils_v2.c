/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_v2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/07/01 13:53:02 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_base(unsigned long long nbr, char *base, int cont)
{
	char	digit;
	
	if ((nbr / 16) != 0)
		cont = print_base((nbr / 16), base, cont + 1);
	digit = base[nbr % 16];
	write(1, &digit, 1);
	return (cont);
}

int	ft_print_char(char a)
{	
	ft_putchar_fd(a, 1);
	return (1);
}

int	ft_print_str(char *word)
{
	if (!word)
		return (sizeof(NULL) - 2);
	ft_putstr_fd(word, 1);
	return (ft_strlen(word));
}

int	ft_print_hexa(unsigned long long	hexadec) //buscarlo en la piscina C04/EX04
{
	int	result;

	result = 0;
	write(1, "0x", 2);
	result = print_base(hexadec, "0123456789abcdef", 0);
	return (result + 3);
}

int	ft_print_xhexa(unsigned int	hexadec) //buscarlo en la piscina C04/EX04
{
	int	result;
	if (hexadec < 0)
		hexadec = 4294967295 + hexadec;
	result = 0;
	result = print_base(hexadec, "0123456789abcdef", 0);
	return (result+1);
}
