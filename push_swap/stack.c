/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:12:53 by aconde-m          #+#    #+#             */
/*   Updated: 2022/10/17 12:25:10 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int size)
{
	t_stack	*stack;
	int		iter;

	iter = 0;
	stack = malloc(size * (sizeof(t_stack)));
	if (!stack)
		return (0);
	
	while (iter < size)
	{
		stack[iter].content = 0;
		stack[iter].size = size;
		stack[iter].isNull = 1;
		iter++;
	}
	return (stack);
}

void	ft_stack_addtop(t_stack *stack, int content)
{
	int iter;
	int size;

	iter = 0;
	size = stack[0].size;	
	while ((size - iter - 2) >= 0)
	{
		stack[(size - iter - 1)].content = stack[(size - iter - 2)].content;
		stack[(size - iter - 1)].isNull = stack[(size - iter - 2)].isNull;
		iter++;
	}
	stack[0].content = content;
	stack[0].isNull = 0;
}

void	ft_stack_addnext(t_stack *stack, int content)
{
	int iter;
	int size;

	iter = 0;
	size = stack[0].size;	
	while (iter < size)
	{
		if (stack[iter].isNull == 0)
			iter++;
		else
		{
			stack[iter].content = content;
			stack[iter].isNull = 0;
			iter = size;
		}
	}
}

void	ft_stack_deltop(t_stack *stack)
{
	int iter;
	int size;

	iter = 0;
	size = stack[0].size;	
	while (iter < size - 1)
	{
		stack[iter].content = stack[(iter + 1)].content;
		stack[iter].isNull = stack[(iter + 1)].isNull;
		iter++;
	}
	stack[size - 1].content = 0;
	stack[size - 1].isNull = 1;
}