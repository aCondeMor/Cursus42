/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:12:53 by aconde-m          #+#    #+#             */
/*   Updated: 2022/11/09 17:45:15 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int size)
{
	t_stack	*stack;
	int		iter;

	iter = 0;
	stack = (t_stack *) malloc(size * (sizeof(t_stack)));
	if (!stack)
		return (0);
	while (iter < size)
	{
		stack[iter].content = 0;
		stack[iter].size = size;
		stack[iter].isnull = 1;
		stack[iter].index = -1;
		stack[iter].totop = -1;
		iter++;
	}
	return (stack);
}

void	ft_stack_addtop(t_stack *stack, int content, int index)
{
	int	iter;
	int	size;

	iter = 0;
	size = stack[0].size;
	while ((size - iter - 2) >= 0)
	{
		stack[(size - iter - 1)].content = stack[(size - iter - 2)].content;
		stack[(size - iter - 1)].isnull = stack[(size - iter - 2)].isnull;
		stack[(size - iter - 1)].index = stack[(size - iter - 2)].index;
		iter++;
	}
	stack[0].content = content;
	stack[0].isnull = 0;
	stack[0].index = index;
}

void	ft_stack_addnext(t_stack *stack, int content, int index)
{
	int	iter;
	int	size;

	iter = 0;
	size = stack[0].size;
	while (iter < size)
	{
		if (stack[iter].isnull == 0)
			iter++;
		else
		{
			stack[iter].content = content;
			stack[iter].isnull = 0;
			stack[iter].index = index;
			iter = size;
		}
	}
}

void	ft_stack_deltop(t_stack *stack)
{
	int	iter;
	int	size;

	iter = 0;
	size = stack[0].size;
	while (iter < size - 1)
	{
		stack[iter].content = stack[(iter + 1)].content;
		stack[iter].isnull = stack[(iter + 1)].isnull;
		stack[iter].index = stack[(iter + 1)].index;
		iter++;
	}
	stack[size - 1].content = 0;
	stack[size - 1].isnull = 1;
	stack[size - 1].index = -1;
}

void	ft_index(t_stack *stack)
{
	int	index;
	int	pos_aux;

	index = 0;
	pos_aux = 0;
	while (index < stack[0].size)
	{
		pos_aux = ft_find_small(stack, 0);
		stack[pos_aux].index = index;
		pos_aux++;
		index++;
	}
}
