/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:57:28 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/15 23:25:30 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int nbr)
{
	int		size;
	long	aux;
	int		neg;
	char	*chain;

	neg = 0;
	aux = nbr;
	if (nbr < 0)
	{
		neg = 1;
		aux = -aux;
	}
	size = ft_getsize(aux);
	if (nbr == 0)
	{
		chain = malloc(2);
		if (!chain)
			return (0);
		chain[0] = '0';
		chain[1] = '\0';
		return (chain);
	}
	chain = ft_recu_itoa(aux, neg + size, neg);
	return (chain);
}
