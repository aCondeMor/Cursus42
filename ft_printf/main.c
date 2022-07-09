/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/07/09 09:00:36 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	c;
	char	p;
	int		d;
	int		result;
	char	cadena[5] = "Hola";

	c = 'j';
	p = 'a';
	d = -10;
	result = ft_printf("esto es un caracter: %c %c %c\n y la otra es: %p\n", 'b', c, p, &cadena);
	ft_printf("esto es un caracter: %d\n", d);
	printf("resultado es:%d\n", result);
	//printf("%llu\n", &cadena);
}