/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/10/27 18:16:46 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(t_stack *stack_a, t_stack *stack_b)
{
	int	iter;
	int	size;

	iter = 0;
	size = stack_a[0].size;
	printf("The current stacks\n");
	while (iter < size)
	{
		if (stack_a[iter].isnull == 0)
		{
			printf("%d\t", stack_a[iter].content);
			printf("[%d]\t", stack_a[iter].index);
		}
		else
			printf("-\t[%d]\t", stack_a[iter].index);
		if (stack_b[iter].isnull == 0)
		{
			printf("%d\t", stack_b[iter].content);
			printf("[%d]\n", stack_b[iter].index);
		}
		else
			printf("-\t[%d]\n", stack_b[iter].index);
		iter++;
	}
	printf("-\t\t-\n");
	printf("a\t\tb\n");
}
