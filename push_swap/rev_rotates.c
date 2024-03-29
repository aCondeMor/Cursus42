/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2023/02/13 16:52:41 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *stack_a, int a)
{
	int	aux;
	int	index;
	int	iter;
	int	size;

	aux = 0;
	index = -1;
	iter = 0;
	size = stack_a[iter].size;
	if ((stack_a[iter].size > 1) && (stack_a[iter + 1].isnull == 0))
	{
		while ((iter < size) && (stack_a[iter].isnull == 0))
			iter++;
		aux = stack_a[iter - 1].content;
		index = stack_a[iter - 1].index;
		stack_a[iter - 1].content = 0;
		stack_a[iter - 1].isnull = 1;
		stack_a[iter - 1].index = -1;
		ft_stack_addtop(stack_a, aux, index);
	}
	if (a == 1)
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack *stack_b, int a)
{
	int	aux;
	int	index;
	int	iter;
	int	size;

	aux = 0;
	index = -1;
	iter = 0;
	size = stack_b[iter].size;
	if ((stack_b[iter].size > 1) && (stack_b[iter + 1].isnull == 0))
	{
		while ((iter < size) && (stack_b[iter].isnull == 0))
			iter++;
		aux = stack_b[iter - 1].content;
		index = stack_b[iter - 1].index;
		stack_b[iter - 1].content = 0;
		stack_b[iter - 1].isnull = 1;
		stack_b[iter - 1].index = -1;
		ft_stack_addtop(stack_b, aux, index);
	}
	if (a == 1)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b, int a)
{
	ft_rra(stack_a, a);
	ft_rrb(stack_b, a);
}
