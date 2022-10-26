/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/10/18 14:41:55 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	content;
	int	size;
	int isNull;
}	t_stack;

//stack
void	ft_stack_addtop(t_stack *stack, int content);
t_stack	*ft_stack_new(int size);
void	ft_stack_addnext(t_stack *stack, int content);
void	ft_stack_deltop(t_stack *stack);
//swaps
void ft_sa(t_stack *stack_a);
void ft_sb(t_stack *stack_b);
void ft_ss(t_stack *stack_a, t_stack *stack_b);
//pushes
void ft_pa(t_stack *stack_a, t_stack *stack_b);
void ft_pb(t_stack *stack_a, t_stack *stack_b);
//rotates
void ft_ra(t_stack *stack_a);
void ft_rb(t_stack *stack_b);
void ft_rr(t_stack *stack_a, t_stack *stack_b);
//reverse rotates
void ft_rra(t_stack *stack_a);
void ft_rrb(t_stack *stack_b);
void ft_rrr(t_stack *stack_a, t_stack *stack_b);
//print stacks
void ft_print(t_stack *stack_a, t_stack *stack_b);
//sort
void ft_sort_nbr(t_stack *stack_a, t_stack *stack_b);
void ft_sort_3elem(t_stack *stack_a);
void ft_return_b(t_stack *stack_a, t_stack *stack_b);
int ft_is_sorted(t_stack *stack_a);
//split
char	**ft_split(char const *s, char c);
int	ft_count_lines(char const *s, char c);
#endif