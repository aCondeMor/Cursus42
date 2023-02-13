/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2023/02/13 16:53:21 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *stack_a, t_stack *stack_b, int a)
{
	if (stack_b[0].isnull == 0)
	{
		ft_stack_addtop(stack_a, stack_b[0].content, stack_b[0].index);
		ft_stack_deltop(stack_b);
	}
	if (a == 1)
		ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b, int a)
{
	if (stack_a[0].isnull == 0)
	{
		ft_stack_addtop(stack_b, stack_a[0].content, stack_a[0].index);
		ft_stack_deltop(stack_a);
	}
	if (a == 1)
		ft_putstr_fd("pb\n", 1);
}
