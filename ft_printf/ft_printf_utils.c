/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/07/09 10:07:40 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x_may_hexa(unsigned int hexadec)
{
	int		result;
	long	cambio;

	cambio = (long)hexadec;
	if (hexadec < 0)
		hexadec = 4294967295 + hexadec;
	result = 0;
	result = print_base(hexadec, "0123456789ABCDEF", 0);
	return (result + 1);
}

char	*ft_recu_itoa(long nbr, int size, int neg)
{
	char	*chain;
	long	aux;
	int		i;

	aux = nbr;
	i = 0;
	chain = malloc(size + 1);
	if (!chain)
		return (0);
	while (aux > 0)
	{
		chain[size - i -1] = ((aux % 10) + '0');
		aux = aux / 10;
		i++;
	}
	chain[size] = '\0';
	if (neg == 1)
		chain[0] = '-';
	return (chain);
}

int	ft_getsize(long nbr)
{
	int		i;
	long	aux;

	i = 0;
	aux = nbr;
	while (aux > 0)
	{
		aux = aux / 10;
		i++;
	}
	return (i);
}

int	ft_newutoa(int nbr)
{
	int		size;
	long	aux;
	int		neg;
	char	*chain;
	char	a;

	neg = 0;
	a = '0';
	aux = nbr;
	if (nbr < 0)
	{
		aux = 4294967296 + nbr;
	}
	size = ft_getsize(aux);
	if (nbr == 0)
	{
		write(1, &a, 1);
		return (1);
	}
	else
		chain = ft_recu_itoa(aux, neg + size, neg);
	write(1, chain, ft_getsize(aux) + neg);
	free(chain);
	return (size + neg);
}

int	ft_newitoa(int nbr)
{
	int		size;
	long	aux;
	int		neg;
	char	*chain;
	char	a;

	neg = 0;
	a = '0';
	aux = nbr;
	if (nbr < 0)
	{
		neg = 1;
		aux = -aux;
	}
	size = ft_getsize(aux);
	if (nbr == 0)
	{
		write(1, &a, 1);
		return (1);
	}
	else
		chain = ft_recu_itoa(aux, neg + size, neg);
	write(1, chain, ft_getsize(aux) + neg);
	free(chain);
	return (size + neg);
}
