/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2023/02/13 16:58:10 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_a)
{
	int	iter;

	iter = 1;
	while ((stack_a[iter].isnull == 0) && (iter < stack_a[0].size))
	{
		if (stack_a[iter].content < stack_a[iter - 1].content)
			return (0);
		iter++;
	}
	return (1);
}

int	ft_find_big(t_stack *stack_a)
{
	int	max;
	int	iter;
	int	pos_max;

	iter = 0;
	max = -2147483647;
	pos_max = 0;
	while ((iter < stack_a[0].size) && (stack_a[iter].isnull == 0))
	{
		if (stack_a[iter].content > max)
		{
			max = stack_a[iter].content;
			pos_max = iter;
		}
		iter++;
	}
	return (pos_max);
}

void	ft_move_max(t_stack *stack_a, t_stack *stack_b, int pos)
{
	int	pivot;

	pivot = ((ft_num_elems(stack_b)) / 2);
	if (pivot >= pos)
	{
		while (pos > 0)
		{
			ft_rb(stack_b, 1);
			pos--;
		}
		ft_pa(stack_a, stack_b, 1);
	}
	else
	{
		while ((stack_b[pos].isnull == 0) && (pos < ft_num_elems(stack_b)))
		{
			ft_rrb(stack_b, 1);
			pos++;
		}
		ft_pa(stack_a, stack_b, 1);
	}
}

int	ft_find_small(t_stack *stack_a, int min_index)
{
	int	iter;
	int	pos_min;
	int	min;

	iter = 0;
	pos_min = 0;
	min = 2147483647;
	while ((iter < stack_a[0].size) && (stack_a[iter].isnull == 0))
	{
		if ((stack_a[iter].content < min) && (stack_a[iter].index < min_index))
		{
			min = stack_a[iter].content;
			pos_min = iter;
		}
		iter++;
	}
	return (pos_min);
}

void	ft_update_totop(t_stack *stack_a)
{
	int	iter;
	int	middle;
	int	size;

	iter = 0;
	size = ft_num_elems(stack_a);
	if ((size % 2) == 0)
		middle = (size / 2) - 1;
	else
		middle = (size / 2);
	while (iter <= middle)
	{
		stack_a[iter].totop = iter;
		iter++;
	}
	while (iter < size)
	{
		stack_a[iter].totop = size - iter;
		iter++;
	}
}
