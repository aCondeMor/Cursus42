/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:03:03 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/17 13:31:03 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(char const *str)
{
	long	i;
	int		neg;
	long	suma;

	suma = 0;
	i = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\t' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) != 0)
	{
		suma = (suma * 10) + (str[i] - '0');
		i++;
	}
	return (suma * neg);
}
