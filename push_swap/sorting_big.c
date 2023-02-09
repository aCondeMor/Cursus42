/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:12:53 by aconde-m          #+#    #+#             */
/*   Updated: 2022/11/09 17:47:19 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_best_min(t_stack *stack_a, int pivot)
{
	int	pos;
	int	to_move;
	int	to_top;

	pos = 0;
	to_move = 0;
	to_top = stack_a[0].size;
	while ((pos < stack_a[0].size) && (stack_a[pos].isnull == 0))
	{
		if ((stack_a[pos].index < (pivot))
			&& (stack_a[pos].totop < to_top))
		{
			to_move = pos;
			to_top = stack_a[pos].totop;
			pos = 0;
		}
		pos++;
	}
	return (to_move);
}

void	ft_move_to_b(t_stack *stack_a, t_stack *stack_b, int magic_nbr)
{
	int	median;
	int	iter;
	int	flag;

	iter = 1;
	flag = 0;
	median = stack_a[0].size / magic_nbr;
	ft_update_totop(stack_a);
	while ((iter < magic_nbr) && (ft_is_sorted(stack_a) == 0))
	{
		while ((flag < (median * iter)) && (ft_is_sorted(stack_a) == 0))
		{
			ft_move_min(stack_a, stack_b,
				ft_find_best_min(stack_a, median * iter));
			ft_update_totop(stack_a);
			flag++;
		}
		iter++;
	}
}

int	ft_sort_a(t_stack *stack_a, t_stack *stack_b)
{
	int	num_elem;
	int	pos_max;

	num_elem = ft_num_elems(stack_a);
	pos_max = 0;
	while ((num_elem > 3) && (ft_is_sorted(stack_a) == 0))
	{
		pos_max = ft_find_small(stack_a, stack_a[0].size);
		ft_move_min(stack_a, stack_b, pos_max);
		pos_max--;
		num_elem--;
	}
	if (ft_is_sorted(stack_a) == 0)
		ft_sort_3elem(stack_a);
	return (num_elem);
}

void	ft_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	pos_max;

	while (ft_num_elems(stack_b) > 0)
	{
		pos_max = ft_find_big(stack_b);
		ft_move_max(stack_a, stack_b, pos_max);
	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	magic_nbr;

	if (stack_a[0].size > 200)
		magic_nbr = 9;
	else
		magic_nbr = 5;
	ft_move_to_b(stack_a, stack_b, magic_nbr);
	ft_sort_a(stack_a, stack_b);
	ft_back_to_a(stack_a, stack_b);
}
