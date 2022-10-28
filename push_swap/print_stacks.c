/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/10/28 10:19:13 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_iswrong(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

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
			printf("%d\t[%d]\t", stack_a[iter].content, stack_a[iter].index);
		else
			printf("-\t[%d]\t", stack_a[iter].index);
		if (stack_b[iter].isnull == 0)
			printf("%d\t[%d]\n", stack_b[iter].content, stack_b[iter].index);
		else
			printf("-\t[%d]\n", stack_b[iter].index);
		iter++;
	}
	printf("-\t\t-\n");
	printf("a\t\tb\n");
}
