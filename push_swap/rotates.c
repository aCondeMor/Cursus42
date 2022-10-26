/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/10/17 13:54:01 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_ra(t_stack *stack_a)
{
	int	aux;
	
	aux = 0;
	if ((stack_a[0].size > 1) && (stack_a[1].isNull == 0))
	{
		aux = stack_a[0].content;
		ft_stack_deltop(stack_a);
		ft_stack_addnext(stack_a, aux);
	}
	printf("ra\n");
}

void ft_rb(t_stack *stack_b)
{
	ft_ra(stack_b);
	printf("rb\n");
}

void ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}
