/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/10/27 11:26:53 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack_a)
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
	printf("sa\n");
}

void	ft_sb(t_stack *stack_b)
{
	ft_sa(stack_b);
	printf("sb\n");
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}
