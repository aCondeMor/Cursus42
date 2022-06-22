/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:41:44 by aconde-m          #+#    #+#             */
/*   Updated: 2022/06/22 19:17:13 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_open(char *filename)
{
	int		fd1;
	char	*table;

	fd1 = open(filename, O_RDONLY);
	table = get_next_line(fd1);
	printf("la linea leida es: %s", table);
	while (table)
	{
	table = get_next_line(fd1);
	printf("la linea leida es: %s", table);
		/* code */
	}
	close(fd1);
	return (table);
}

int	main(void)
{
	char	*filename;
	char	*dicts;

	filename = "test1.txt";
	dicts = ft_open(filename);
}
