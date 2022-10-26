/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/10/13 16:14:09 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print(t_stack *stack_a, t_stack *stack_b)
{
	int	iter;
	int	size;

	iter = 0;
	size = stack_a[0].size;
	printf("The current stacks\n");
	while (iter < size)
	{
		if (stack_a[iter].isNull == 0)
			printf("%d\t", stack_a[iter].content);
		else
			printf("-\t");
		if (stack_b[iter].isNull == 0)
			printf("%d\n", stack_b[iter].content);
		else
			printf("-\n");
		iter++;
	}
	printf("-\t-\n");
	printf("a\tb\n");
}
