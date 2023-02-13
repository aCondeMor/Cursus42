/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:12:53 by aconde-m          #+#    #+#             */
/*   Updated: 2023/02/13 16:55:42 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_return_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b[0].isnull == 0)
		ft_pa(stack_a, stack_b, 1);
}

void	ft_sort_3elem(t_stack *stack_a)
{
	int	pos_min;
	int	pos_max;

	pos_min = ft_find_small(stack_a, stack_a[0].size);
	pos_max = ft_find_big(stack_a);
	if ((pos_min == 1) && (pos_max == 2))
		ft_sa(stack_a, 1);
	else if ((pos_min == 2) && (pos_max == 0))
	{
		ft_sa(stack_a, 1);
		ft_rra(stack_a, 1);
	}
	else if ((pos_min == 1) && (pos_max == 0))
		ft_ra(stack_a, 1);
	else if ((pos_min == 0) && (pos_max == 1))
	{
		ft_sa(stack_a, 1);
		ft_ra(stack_a, 1);
	}
	else if ((pos_min == 2) && (pos_max == 1))
		ft_rra(stack_a, 1);
}

int	ft_num_elems(t_stack *stack_a)
{
	int	iter;

	iter = 0;
	while ((stack_a[iter].isnull == 0) && (iter < stack_a[0].size))
		iter++;
	return (iter);
}

void	ft_move_min(t_stack *stack_a, t_stack *stack_b, int pos_min)
{
	int	pivot;

	pivot = (ft_num_elems(stack_a) / 2);
	if (pivot >= pos_min)
	{
		while (pos_min > 0)
		{
			ft_ra(stack_a, 1);
			pos_min--;
		}
		ft_pb(stack_a, stack_b, 1);
	}
	else
	{
		while ((stack_a[pos_min].isnull == 0) && (pos_min < stack_a[0].size))
		{
			ft_rra(stack_a, 1);
			pos_min++;
		}
		ft_pb(stack_a, stack_b, 1);
	}
}

void	ft_sort_nbr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a[0].size > 10)
		ft_sort(stack_a, stack_b);
	else if (stack_a[0].size == 3)
		ft_sort_3elem(stack_a);
	else if (stack_a[0].size == 2)
		ft_ra(stack_a, 1);
	else if (stack_a[0].size <= 10)
	{
		while (stack_a[3].isnull == 0)
			ft_move_min(stack_a, stack_b,
				ft_find_small(stack_a, stack_a[0].size));
		ft_sort_3elem(stack_a);
		ft_return_b(stack_a, stack_b);
	}
}
