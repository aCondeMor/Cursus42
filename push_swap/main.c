/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2022/11/03 12:45:53 by aconde-m         ###   ########.fr       */
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

void	ft_check_dupl(char **argv)
{
	int	init;
	int	iter;

	iter = 2;
	while (argv[iter])
	{
		init = 1;
		while (init < iter)
		{
			if (!ft_strncmp(argv[init], argv[iter], ft_strlen(argv[iter]) + 1))
				ft_iswrong();
			init++;
		}
		iter++;
	}
}

int	ft_get_num(char *number)
{
	int				iter;
	int				neg;
	long long int	suma;

	iter = 0;
	neg = 1;
	suma = 0;
	if (number[iter] == '-')
	{
		neg = -1;
		iter++;
	}
	else if (number[iter] == '+')
		iter++;
	while (number[iter] != '\0')
	{
		if (ft_isdigit(number[iter]) != 0)
			suma = (suma * 10) + (number[iter] - '0');
		if (((suma > 2147483648) && (neg == -1))
			|| (ft_isdigit(number[iter]) == 0)
			|| ((suma >= 2147483648) && (neg == 1)))
			ft_iswrong();
		iter++;
	}
	return (suma * neg);
}

void	ft_init(int argc, char *argv[])
{
	int		iter;
	int		aux;
	t_stack	*stack_a;
	t_stack	*stack_b;

	aux = 0;
	iter = 1;
	ft_check_dupl(argv);
	stack_a = ft_stack_new(argc);
	stack_b = ft_stack_new(argc);
	while (iter <= argc)
	{
		aux = ft_get_num(argv[iter]);
		ft_stack_addnext(stack_a, aux, -1);
		iter++;
	}
	if (ft_is_sorted(stack_a) == 0)
	{
		ft_index(stack_a);
		//ft_print(stack_a, stack_b);
		ft_sort_nbr(stack_a, stack_b);
	}
	//ft_print(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
}

int	main(int argc, char *argv[])
{
	char	**aux;

	aux = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		aux = ft_split(ft_strjoin("0 ", argv[1]), 32);
		ft_init((ft_count_lines(argv[1], 32)), aux);
	}
	else
		ft_init((argc - 1), argv);
	free(aux);
}
