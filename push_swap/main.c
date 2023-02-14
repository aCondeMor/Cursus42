/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconde-m <aconde-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:59:14 by aconde-m          #+#    #+#             */
/*   Updated: 2023/02/14 12:32:32 by aconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_dupl(char **argv)
{
	int	init;
	int	iter;

	iter = 1;
	while (argv[iter])
	{
		init = 0;
		while (init < iter)
		{
			if (!ft_strncmp(argv[init], argv[iter], ft_strlen(argv[iter]) + 1))
				ft_iswrong("Error");
			init++;
		}
		iter++;
	}
}

void	ft_check_in_number(long long int suma, int neg, char digit)
{
	if (((suma > 2147483648) && (neg == -1))
		|| (ft_isdigit(digit) == 0)
		|| ((suma >= 2147483648) && (neg == 1)))
		ft_iswrong("Error");
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
		ft_check_in_number(suma, neg, number[iter]);
		iter++;
	}
	if ((iter == 1) && (ft_isdigit(number[0]) == 0))
		ft_iswrong("Error");
	return (suma * neg);
}

void	ft_init(int argc, char *argv[])
{
	int		iter;
	int		aux;
	t_stack	*stack_a;
	t_stack	*stack_b;

	aux = 0;
	iter = 0;
	if (argc > 1)
		ft_check_dupl(argv);
	stack_a = ft_stack_new(argc);
	stack_b = ft_stack_new(argc);
	while (iter < argc)
	{
		aux = ft_get_num(argv[iter]);
		ft_stack_addnext(stack_a, aux, -1);
		iter++;
	}
	if (ft_is_sorted(stack_a) == 0)
	{
		ft_index(stack_a);
		ft_sort_nbr(stack_a, stack_b);
	}
	free(stack_a);
	free(stack_b);
}

void prueba (void)
{
	System.leaks(push_swap);
}

int	main(int argc, char *argv[])
{
	char	**aux;
	int		lines_nbr;
	int		i;

	
	i = 0;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		lines_nbr = ft_count_lines(argv[1], 32);
		aux = ft_split(argv[1], 32);
		ft_init(lines_nbr, aux);
		while (i < lines_nbr)
		{
			free(aux[i]);
			i++;
		}
		free(aux);
	}
	else
		ft_init(argc - 1, &argv[1]);
	atexit(prueba);
	return (0);
}
