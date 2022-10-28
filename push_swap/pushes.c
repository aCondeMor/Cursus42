/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/10/27 18:21:03 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b[0].isnull == 0)
	{
		ft_stack_addtop(stack_a, stack_b[0].content, stack_b[0].index);
		ft_stack_deltop(stack_b);
	}
	printf("pa\n");
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a[0].isnull == 0)
	{
		ft_stack_addtop(stack_b, stack_a[0].content, stack_a[0].index);
		ft_stack_deltop(stack_a);
	}
	printf("pb\n");
}
