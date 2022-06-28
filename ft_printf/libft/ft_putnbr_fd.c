/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:04:23 by aconde-m          #+#    #+#             */
/*   Updated: 2022/05/15 23:20:15 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	long int	newnbr;
	char		c;

	newnbr = nbr;
	if (newnbr < 0)
	{
		ft_putchar_fd('-', fd);
		newnbr = -newnbr;
	}
	if (newnbr > 9)
		ft_putnbr_fd((newnbr / 10), fd);
	c = (newnbr % 10) + '0';
	ft_putchar_fd(c, fd);
}
