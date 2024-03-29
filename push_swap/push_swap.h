/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2023/02/13 16:59:27 by aconde-m         ###   ########.fr       */
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
	int	isnull;
	int	index;
	int	totop;
}	t_stack;

//stack
void	ft_stack_addtop(t_stack *stack, int content, int index);
t_stack	*ft_stack_new(int size);
void	ft_stack_addnext(t_stack *stack, int content, int index);
void	ft_stack_deltop(t_stack *stack);
//swaps
void	ft_sa(t_stack *stack_a, int a);
void	ft_sb(t_stack *stack_b, int a);
void	ft_ss(t_stack *stack_a, t_stack *stack_b, int a);
//pushes
void	ft_pa(t_stack *stack_a, t_stack *stack_b, int a);
void	ft_pb(t_stack *stack_a, t_stack *stack_b, int a);
//rotates
void	ft_ra(t_stack *stack_a, int a);
void	ft_rb(t_stack *stack_b, int a);
void	ft_rr(t_stack *stack_a, t_stack *stack_b, int a);
//reverse rotates
void	ft_rra(t_stack *stack_a, int a);
void	ft_rrb(t_stack *stack_b, int a);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b, int a);
//print stacks
void	ft_print(t_stack *stack_a, t_stack *stack_b);
void	ft_iswrong(char *error);
//sort
void	ft_sort_nbr(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_3elem(t_stack *stack_a);
void	ft_return_b(t_stack *stack_a, t_stack *stack_b);
int		ft_is_sorted(t_stack *stack_a);
int		ft_find_small(t_stack *stack_a, int min);
int		ft_find_big(t_stack *stack_a);
void	ft_index(t_stack *stack);
void	ft_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_move_min(t_stack *stack_a, t_stack *stack_b, int pos_min);
int		ft_num_elems(t_stack *stack_a);
void	ft_move_max(t_stack *stack_a, t_stack *stack_b, int pos);
void	ft_update_totop(t_stack *stack_a);
//split
char	**ft_split(char const *s, char c);
int		ft_count_lines(char const *s, char c);
//Bonus
void	ft_checker(t_stack *stack_a, t_stack *stack_b);
//get_next_line
char	*get_next_line(int file);
#endif