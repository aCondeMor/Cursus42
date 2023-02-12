/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2023/02/09 19:15:22 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_iswrong(char *error)
{
	ft_putendl_fd(error, 2);
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
			printf("%d\t[%d]\t[%d]\t", stack_a[iter].content,
				stack_a[iter].index, stack_a[iter].totop);
		else
			printf("-\t[%d]\t[%d]\t", stack_a[iter].index, stack_a[iter].totop);
		if (stack_b[iter].isnull == 0)
			printf("%d\t[%d]\t[%d]\n", stack_b[iter].content,
				stack_b[iter].index, stack_b[iter].totop);
		else
			printf("-\t[%d]\t[%d]\n", stack_b[iter].index, stack_b[iter].totop);
		iter++;
	}
	printf("-\t\t-\n");
	printf("a\t\tb\n");
}
