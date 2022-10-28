/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:12:53 by aconde-m          #+#    #+#             */
/*   Updated: 2022/10/27 19:28:31 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void ft_move_to_b(t_stack *stack_a, t_stack *stack_b, int magic_nbr)
{
	int	median;
	int	iter;
	int	pos;

	iter = 1;
	pos = 0;
	median = stack_a[0].size / magic_nbr;
	while (iter < magic_nbr)
	{
		while ((pos < stack_a[0].size) && (stack_a[pos].isnull == 0))
		{
			if (stack_a[pos].index < (median * iter))
			{
				ft_move_min(stack_a, stack_b, pos);
				pos = 0;
			}
			pos++;
		}
		pos = 0;
		iter++;
	}
}

void	ft_sort_a(t_stack *stack_a, t_stack *stack_b)
{
	int	num_elem;
	int	pos_max;

	num_elem = ft_num_elems(stack_a);
	pos_max = 0;
	while (num_elem > 0)
	{
		pos_max = ft_find_small(stack_a, stack_a[0].size);
		ft_move_min(stack_a, stack_b, pos_max);
		pos_max--;
		num_elem--;
	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	num_elem;

	ft_move_to_b(stack_a, stack_b, 4);
	num_elem = ft_num_elems(stack_a);
	ft_sort_a(stack_a, stack_b);
	// esto hacerlo en una funcion global para todos y listo
	while (num_elem > 0)
	{
		ft_pa(stack_a, stack_b);
		num_elem--;
	}
	ft_print(stack_a, stack_b);
}
