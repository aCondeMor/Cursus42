/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/10/17 13:19:53 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rra(t_stack *stack_a)
{
	int	aux;
	int iter;
	int size;
	
	aux = 0;
	iter = 0;
	size = stack_a[iter].size;
	if ((stack_a[iter].size > 1) && (stack_a[iter + 1].isNull == 0))
	{
		while ((iter < size) && (stack_a[iter].isNull == 0))
			iter++;
		aux = stack_a[iter-1].content;
		stack_a[iter-1].content = 0;
		stack_a[iter-1].isNull = 1;
		ft_stack_addtop(stack_a, aux);
	}
	printf("rra\n");
}

void ft_rrb(t_stack *stack_b)
{
	ft_rra(stack_b);
	printf("rrb\n");
}

void ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}
