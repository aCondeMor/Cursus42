/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:12:53 by aconde-m          #+#    #+#             */
/*   Updated: 2022/10/17 15:48:43 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_return_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b[0].isNull == 0)
		ft_pa(stack_a, stack_b);
}

int	ft_find_big(t_stack *stack_a)
{
	int max;
	int iter;
	int pos_max;

	iter = 0;
	max = -2147483647;
	pos_max = 0;
	while ((iter < stack_a[0].size) && (stack_a[iter].isNull == 0))
	{
		if (stack_a[iter].content > max)
		{
			max = stack_a[iter].content;
			pos_max = iter;
		}
		iter++;
	}
	return(pos_max);
}

int	ft_find_small(t_stack *stack_a)
{
	int min;
	int iter;
	int pos_min;

	iter = 0;
	min = 2147483647;
	pos_min = 0;
	while ((iter < stack_a[0].size) && (stack_a[iter].isNull == 0)) 
	{
		if (stack_a[iter].content < min) 
		{
			min = stack_a[iter].content;
			pos_min = iter;
		}
		iter++;
	}
	return(pos_min);
}

void ft_sort_3elem(t_stack *stack_a)
{
	int pos_min;
	int pos_max;

	pos_min = ft_find_small(stack_a);
	pos_max = ft_find_big(stack_a);
	if ((pos_min == 1) && (pos_max == 2))
		ft_sa(stack_a);
	else if ((pos_min == 2) && (pos_max == 0))
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if ((pos_min == 1) && (pos_max == 0))
		ft_ra(stack_a);
	else if ((pos_min == 0) && (pos_max == 1))
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if ((pos_min == 2) && (pos_max == 1))
		ft_rra(stack_a);
}
int ft_num_elems(t_stack *stack_a)
{
	int iter;

	iter = 0;
	while (stack_a[iter].isNull == 0)
		iter++;
	return(iter);
}
void ft_move_min(t_stack *stack_a, t_stack *stack_b, int pos_min)
{
	int pivot;

	pivot = (ft_num_elems(stack_a) / 2);
	if (pivot >= pos_min)
	{
		while(pos_min > 0)
		{
			ft_ra(stack_a);
			pos_min--;
		}
		ft_pb(stack_a, stack_b);
	}
	else
	{
		while((stack_a[pos_min].isNull == 0) && (pos_min < stack_a[0].size))
		{
			ft_rra(stack_a);
			pos_min++;
		}
		ft_pb(stack_a, stack_b);
	}
}
void ft_sort_nbr(t_stack *stack_a, t_stack *stack_b)
{
	if(stack_a[0].size > 3)
	{
		while (stack_a[3].isNull == 0)
			ft_move_min(stack_a, stack_b, ft_find_small(stack_a));
		ft_sort_3elem(stack_a);
		ft_return_b(stack_a, stack_b);
	}
	else if(stack_a[0].size == 3)
		ft_sort_3elem(stack_a);
	else if(stack_a[0].size == 2)
	{
		if(stack_a[0].content > stack_a[1].content)
			ft_ra(stack_a);
	}
	
}