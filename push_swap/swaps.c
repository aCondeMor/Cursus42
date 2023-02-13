/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2023/02/13 16:54:12 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack_a, int a)
{
	int	aux;
	int	aux_null;

	aux = 0;
	aux_null = 0;
	if ((stack_a[0].size > 1) && (stack_a[1].isnull == 0))
	{
		aux = stack_a[0].content;
		aux_null = stack_a[0].isnull;
		stack_a[0].content = stack_a[1].content;
		stack_a[0].isnull = stack_a[1].isnull;
		stack_a[1].content = aux;
		stack_a[1].isnull = aux_null;
	}
	if (a == 1)
		ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack *stack_b, int a)
{
	int	aux;
	int	aux_null;

	aux = 0;
	aux_null = 0;
	if ((stack_b[0].size > 1) && (stack_b[1].isnull == 0))
	{
		aux = stack_b[0].content;
		aux_null = stack_b[0].isnull;
		stack_b[0].content = stack_b[1].content;
		stack_b[0].isnull = stack_b[1].isnull;
		stack_b[1].content = aux;
		stack_b[1].isnull = aux_null;
	}
	if (a == 1)
		ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b, int a)
{
	ft_sa(stack_a, a);
	ft_sb(stack_b, a);
}
