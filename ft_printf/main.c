/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/06/28 16:57:52 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	c;
	char	p;
	int		result;
	char	cadena[5] = "Hola";

	c = 'j';
	p = 'a';
	result = ft_printf("esto es un caracter: %c\n y la otra es: %s\n", c, cadena);
	printf("resultado es:%d\n", result);
	printf("%p\n", &cadena);
}