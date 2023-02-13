/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2023/02/13 16:51:42 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *stack_a, int a)
{
	int	aux;
	int	index;

	aux = 0;
	index = -1;
	if ((stack_a[0].size > 1) && (stack_a[1].isnull == 0))
	{
		aux = stack_a[0].content;
		index = stack_a[0].index;
		ft_stack_deltop(stack_a);
		ft_stack_addnext(stack_a, aux, index);
	}
	if (a == 1)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack *stack_b, int a)
{
	int	aux;
	int	index;

	aux = 0;
	index = -1;
	if ((stack_b[0].size > 1) && (stack_b[1].isnull == 0))
	{
		aux = stack_b[0].content;
		index = stack_b[0].index;
		ft_stack_deltop(stack_b);
		ft_stack_addnext(stack_b, aux, index);
	}
	if (a == 1)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b, int a)
{
	ft_ra(stack_a, a);
	ft_rb(stack_b, a);
}
