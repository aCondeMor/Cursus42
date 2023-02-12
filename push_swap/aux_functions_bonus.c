/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2023/02/09 20:00:58 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkmov(t_stack *stack_a, t_stack *stack_b, char *movement)
{
	if (ft_strncmp("sa\n", movement, 4))
		ft_sa(stack_a);
	else if (ft_strncmp("sb\n", movement, 4))
		ft_sb(stack_b);
	else if (ft_strncmp("ra\n", movement, 4))
		ft_ra(stack_a);
	else if (ft_strncmp("rb\n", movement, 4))
		ft_rb(stack_b);
	else if (ft_strncmp("rr\n", movement, 4))
		ft_rr(stack_a, stack_b);
	else if (ft_strncmp("rra\n", movement, 5))
		ft_rra(stack_a);
	else if (ft_strncmp("rrb\n", movement, 5))
		ft_rrb(stack_b);
	else if (ft_strncmp("rr\n", movement, 4))
		ft_rr(stack_a, stack_b);
	if (ft_strncmp("pa\n", movement, 4))
		ft_pa(stack_a, stack_b);
	else if (ft_strncmp("pb\n", movement, 4))
		ft_pb(stack_b, stack_a);
	else
		return (1);
	return (0);
}

int	ft_getmovements(t_stack *stack_a, t_stack *stack_b)
{
	char	*movement;

	movement = get_next_line(1);
	while (movement)
	{
		if (ft_checkmov(stack_a, stack_b, movement) == 0)
		{
			free(movement);
			movement = get_next_line(0);
		}
		else
		{
			free(movement);
			return (1);
		}
	}
	ft_putendl_fd(movement, 1);
	return (0);
}

void	ft_checker(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_getmovements(stack_a, stack_b) == 0)
	{
		if (ft_is_sorted(stack_a) == 1)
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
	}
	else
		ft_putendl_fd("ERROR, movimiento no existe", 1);
}
